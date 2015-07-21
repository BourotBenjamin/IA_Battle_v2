#include "ExtractorB.h"
#include "ExtractorConstructor.h"


ExtractorB::ExtractorB(std::string* code)
{
	extractorArmy = std::move(ExtractorConstructor::createArmyExtractor(code));
}


ExtractorB::~ExtractorB()
{
	extractorArmy.release();
}

Point& ExtractorB::get(Unit& unit, Army& allies, Army& oponents)
{
	int nb_unit = 0;
	double sumX = 0;
	double sumY = 0;
	UnitSet& units = extractorArmy->get(unit, allies, oponents);
	if (units.size() == 0)
		throw std::invalid_argument("No units");
	for each(auto& u in units)
	{
		nb_unit++;
		sumX += u->getPosition().getX();
		sumY += u->getPosition().getX();
	}
	p = Point(sumX / nb_unit, sumY / nb_unit);
	return p;
}

std::string ExtractorB::getCode()const
{
	return std::string("B") + extractorArmy->getCode();
}

std::string ExtractorB::generateRandomCode(int i)
{
	return std::string("B") + ExtractorConstructor::generateRandomExtractorCode(i, ExtractorType::ARMY);
}