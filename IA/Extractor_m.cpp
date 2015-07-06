#include "Extractor_m.h"


Extractor_m::Extractor_m()
{
}


Extractor_m::~Extractor_m()
{
}

float& Extractor_m::get(Unit& unit, Army& allies, Army& oponents)
{
	float min = FLT_MAX;
	for each(auto& u in extractorArmy->get(unit, allies, oponents))
	{
		if (u->getCapacity(capacity)->getValue() < min)
			min = u->getCapacity(capacity)->getValue();
	}
	return min;
}

std::string Extractor_m::getCode()
{
	return std::string("M") + std::to_string(capacity) + extractorArmy->getCode();
}
