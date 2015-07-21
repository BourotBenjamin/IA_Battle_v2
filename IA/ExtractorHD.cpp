#include "ExtractorHD.h"
#include "ExtractorConstructor.h"


ExtractorHD::ExtractorHD(std::string* code)
{
	extractorArmy = std::move(ExtractorConstructor::createArmyExtractor(code));
	extractorPoint = std::move(ExtractorConstructor::createPointExtractor(code));
}


ExtractorHD::~ExtractorHD()
{
	extractorArmy.release();
	extractorPoint.release();
}

Unit& ExtractorHD::get(Unit& unit, Army& allies, Army& oponents)
{
	double max = -1;
	std::shared_ptr<Unit> furthest = nullptr;
	Point& p = extractorPoint->get(unit, allies, oponents);
	UnitSet& units = extractorArmy->get(unit, allies, oponents);
	if (units.size() == 0)
		throw std::invalid_argument("No units");
	for each(auto& u in units)
	{
		double dist = u->getPosition().distance(p);
		if (dist > max)
			furthest = u;
	}
	return (*furthest);
}

std::string ExtractorHD::getCode()
{
	return std::string("HD") + extractorArmy->getCode() + extractorPoint->getCode();
}

std::string ExtractorHD::generateRandomCode(int i)
{
	return std::string("HD") + ExtractorConstructor::generateRandomExtractorCode(i, ExtractorType::ARMY) + ExtractorConstructor::generateRandomExtractorCode(i, ExtractorType::POINT);
}