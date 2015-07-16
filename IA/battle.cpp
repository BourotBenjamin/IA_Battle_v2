#include "battle.hpp"
#include "Army.hpp"


#include <vector>
#include <algorithm>
#include <memory>
#include <stdexcept>
#include <iostream>

BattleParameter parameter;

//Struct used to manipulate a unit together with its army and its opponents
struct UnitChoice {
    Army* army;
    Army* opponents;
    int unitId;
    UnitChoice(int id, Army* a, Army* o):unitId(id),army(a), opponents(o) {}
};

//Run a fight between the two given armies, and store their score in the given variable.
void fight(const Army& a, const Army& b, int& scoreA, int& scoreB,OpenGLRenderer renderer, bool log)
{
    if(log) {
        std::cout<<"-------------------------------"<<std::endl;
        std::cout<<"FIGHT"<<std::endl;
        std::cout<<"-------------------------------"<<std::endl;
    }

    Army myA = a;
    Army myB = b;

    AI ai;
    int turn = 1;

    parameter = BattleParameter(myA, myB, scoreA, scoreB, log, ai, turn);

    renderer.StartDisplay(&parameter);//,executeOneTurn);
}

void executeOneTurn(BattleParameter parameter)
{
    Army A = parameter.myA;
    Army B = parameter.myB;
	if (parameter.log) {
		std::cout << "-------------------------------" << std::endl;
		std::cout << "Turn " << (parameter.turn) << std::endl;
		std::cout << "-------------------------------" << std::endl;
	}

	std::vector<UnitChoice> order;
	std::transform(A.getUnitsList().begin(), A.getUnitsList().end(), std::back_inserter(order),
		[&A, &B](std::unique_ptr<Unit>& u) {
		u->refresh();
		return UnitChoice(u->getId(), &A, &B);
	});
	std::transform(B.getUnitsList().begin(), B.getUnitsList().end(), std::back_inserter(order),
		[&A, &B](std::unique_ptr<Unit>& u) {
		u->refresh();
		return UnitChoice(u->getId(), &B, &A);
	});
	std::random_shuffle(order.begin(), order.end());

	for (auto it = order.begin(); it != order.end(); it++) {
		try {
			if (parameter.log)std::cout << "Unit#" << it->unitId << " (Army " << ((it->army) == &A ? "A" : "B") << ") : ";
			Unit& unit = it->army->getUnit(it->unitId);
			std::unique_ptr<Action> action = parameter.ai(unit, *(it->army), *(it->opponents));
			action->execute(parameter.log);
			it->opponents->purge();
		}
		catch (std::invalid_argument e) {

			//can happens if the unit is already dead or if an army is empty
			continue;
		}
	}

	parameter.myA = A;
    parameter.myB = B;

	if (A.size() <= 0 || B.size() <= 0 || parameter.turn++ >= 10000)
		endBattle(parameter);
}

void endBattle(BattleParameter parameter)
{
	if (parameter.log) {
		if (parameter.myA.size() == 0) {
			std::cout << "Army B win " << parameter.myB.size() << " to 0" << std::endl;
		}
		else {
			std::cout << "Army A win " << parameter.myA.size() << " to 0" << std::endl;
		}
	}
	parameter.scoreA = parameter.myA.size() - parameter.myB.size();
	parameter.scoreB = parameter.myB.size() - parameter.myA.size();
	if (parameter.scoreA < 0)parameter.scoreA = 0;
	if (parameter.scoreB < 0)parameter.scoreB = 0;
	if (parameter.log) {
		std::cout << "-------------------------------" << std::endl;
		std::cout << "END FIGHT" << std::endl;
		std::cout << "-------------------------------" << std::endl;
	}
	glutLeaveMainLoop();
}

