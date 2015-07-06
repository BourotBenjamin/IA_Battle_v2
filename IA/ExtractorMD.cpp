#include "ExtractorMD.h"


ExtractorMD::ExtractorMD()
{
}


ExtractorMD::~ExtractorMD()
{
}

float ExtractorMD::get(Unit& unit, Army& allies, Army& oponents)
{
	float max = -1;
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
