#include "ExtractorL.h"


ExtractorL::ExtractorL()
{
}


ExtractorL::~ExtractorL()
{
}

Unit ExtractorL::get(Unit& unit, Army& allies, Army& oponents)
{
	return extractorArmy->get(unit, allies, oponents).getLowestUnit(capacity);
}

std::string ExtractorL::getCode()
{
	return std::string("L") + std::to_string(capacity) + extractorArmy->getCode();
}

