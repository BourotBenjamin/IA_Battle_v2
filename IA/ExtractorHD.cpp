#include "ExtractorHD.h"


ExtractorHD::ExtractorHD(std::string* code)
{
	extractorArmy = (Extractor<UnitSet>*) ExtractorConstructor::create(code);
	extractorPoint = (Extractor<Point>*) ExtractorConstructor::create(code);
}


ExtractorHD::~ExtractorHD()
{
}

Unit& ExtractorHD::get(Unit& unit, Army& allies, Army& oponents)
{
	float max = -1;
	std::shared_ptr<Unit> furthest = nullptr;
	Point p = extractorPoint->get(unit, allies, oponents);
	for each(auto& u in extractorArmy->get(unit, allies, oponents))
	{
		float dist = u->getPosition().distance(p);
		if (dist > max)
			furthest = u;
	}
	return (*furthest);
}

std::string ExtractorHD::getCode()
{
	return std::string("HD") + extractorArmy->getCode() + extractorPoint->getCode();
}
