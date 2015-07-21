#include "ExtractorMD.h"
#include "ExtractorConstructor.h"


ExtractorMD::ExtractorMD(std::string* code)
{
	extractorArmy = std::move(ExtractorConstructor::createArmyExtractor(code));
	extractorPoint = std::move(ExtractorConstructor::createPointExtractor(code));
}


ExtractorMD::~ExtractorMD()
{
	extractorPoint.release();
	extractorArmy.release();
}

double& ExtractorMD::get(Unit& unit, Army& allies, Army& oponents)
{
	max = -1;
	Point& p = extractorPoint->get(unit, allies, oponents);
	UnitSet& units = extractorArmy->get(unit, allies, oponents);
	if (units.size() == 0)
		throw std::invalid_argument("No units");
	for each(auto& u in units)
	{
		double dist = u->getPosition().distance(p);
		if (dist > max)
			max = dist;
	}
	return max;
}

std::string ExtractorMD::getCode()const
{
	return std::string("MD") + extractorArmy->getCode() + extractorPoint->getCode();
}

std::string ExtractorMD::generateRandomCode(int i)
{
	return std::string("MD") + ExtractorConstructor::generateRandomExtractorCode(i, ExtractorType::ARMY) + ExtractorConstructor::generateRandomExtractorCode(i, ExtractorType::POINT);
}
