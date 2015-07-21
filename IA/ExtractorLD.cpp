#include "ExtractorLD.h"
#include "ExtractorConstructor.h"


ExtractorLD::ExtractorLD(std::string* code)
{
	extractorArmy = std::move(ExtractorConstructor::createArmyExtractor(code));
	extractorPoint = std::move(ExtractorConstructor::createPointExtractor(code));
}


ExtractorLD::~ExtractorLD()
{
	extractorArmy.release();
	extractorPoint.release();
}

Unit& ExtractorLD::get(Unit& unit, Army& allies, Army& oponents)
{
	double min = FLT_MAX;
	std::shared_ptr<Unit> nearest = nullptr;
	Point& p = extractorPoint->get(unit, allies, oponents);
	UnitSet& units = extractorArmy->get(unit, allies, oponents);
	if (units.size() == 0)
		throw std::invalid_argument("No units");
	for each(auto& u in units)
	{
		double dist = u->getPosition().distance(p);
		if (dist < min)
		{
			nearest = u;
		}
	}
	return (*nearest);
}

std::string ExtractorLD::getCode()
{
	return std::string("LD") + extractorArmy->getCode() + extractorPoint->getCode();
}

std::string ExtractorLD::generateRandomCode(int i)
{
	return std::string("LD") + ExtractorConstructor::generateRandomExtractorCode(i, ExtractorType::ARMY) + ExtractorConstructor::generateRandomExtractorCode(i, ExtractorType::POINT);
}