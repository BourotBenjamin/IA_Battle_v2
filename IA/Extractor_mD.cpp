#include "Extractor_mD.h"


Extractor_mD::Extractor_mD()
{
}


Extractor_mD::~Extractor_mD()
{
}

float Extractor_mD::get(Unit& unit, Army& allies, Army& oponents)
{
	float min = FLT_MAX;
	Point p = extractorPoint->get(unit, allies, oponents);
	for each(auto& u in extractorArmy->get(unit, allies, oponents))
	{
		float dist = u->getPosition().distance(p);
		if (dist < min)
			min = dist;
	}
	return min;
}

std::string Extractor_mD::getCode()
{
	return std::string("mD") + extractorArmy->getCode() + extractorPoint->getCode();
}
