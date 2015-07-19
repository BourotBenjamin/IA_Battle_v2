#include <memory>
#include "AI.hpp"
#include "Action.hpp"
#include "MoveAction.hpp"
#include "ShotAction.hpp"
#include "EmptyAction.hpp"
#include "Unit.hpp"
#include "Army.hpp"
#include <iostream>

//Parenthesis overloading for applying the AI on the unit provided in parameter
//Return the action which have to be done by the unit in this context
std::unique_ptr<Action> AI::operator()(Unit& unit, Army& allies, Army& opponents)
{
	return unit.getTree()->execute(&unit, &allies, &opponents);
}
