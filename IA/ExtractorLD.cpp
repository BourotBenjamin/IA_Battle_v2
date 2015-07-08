#include "ExtractorLD.h"


ExtractorLD::ExtractorLD(std::string* code)
{
	extractorArmy = (Extractor<UnitSet>*) ExtractorConstructor::create(code);
	extractorPoint = (Extractor<Point>*) ExtractorConstructor::create(code);
}


ExtractorLD::~ExtractorLD()
{
}

Unit& ExtractorLD::get(Unit& unit, Army& allies, Army& oponents)
{
	float min = FLT_MAX;
	std::shared_ptr<Unit> nearest = nullptr;
	Point p = extractorPoint->get(unit, allies, oponents);
	for each(auto& u in extractorArmy->get(unit, allies, oponents))
	{
		float dist = u->getPosition().distance(p);
		if (dist < min)
			nearest = u;
	}
	return (*nearest);
}

std::string ExtractorLD::getCode()
{
	return std::string("LD") + extractorArmy->getCode() + extractorPoint->getCode();
}
