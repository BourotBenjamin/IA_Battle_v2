#include "ExtractorM.h"


ExtractorM::ExtractorM()
{
}


ExtractorM::~ExtractorM()
{
}

float ExtractorM::get(Unit& unit, Army& allies, Army& oponents)
{
	float max = -1;
	for each(auto& u in extractorArmy->get(unit, allies, oponents))
	{
		if (u->getCapacity(capacity)->getValue() > max)
			max = u->getCapacity(capacity)->getValue();
	}
	return max;
}

std::string ExtractorM::getCode()
{
	return std::string("M") + std::to_string(capacity) + extractorArmy->getCode();
}
