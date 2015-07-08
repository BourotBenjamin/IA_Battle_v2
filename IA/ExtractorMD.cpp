#include "ExtractorMD.h"


ExtractorMD::ExtractorMD(std::string* code)
{
	extractorArmy = (Extractor<UnitSet>*) ExtractorConstructor::create(code);
	extractorPoint = (Extractor<Point>*) ExtractorConstructor::create(code);
}


ExtractorMD::~ExtractorMD()
{
}

double& ExtractorMD::get(Unit& unit, Army& allies, Army& oponents)
{
	double max = -1;
	Point p = extractorPoint->get(unit, allies, oponents);
	for each(auto& u in extractorArmy->get(unit, allies, oponents))
	{
		float dist = u->getPosition().distance(p);
		if (dist > max)
			max = dist;
	}
	return max;
}

std::string ExtractorMD::getCode()
{
	return std::string("MD") + extractorArmy->getCode() + extractorPoint->getCode();
}
