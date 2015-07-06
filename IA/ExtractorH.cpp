#include "ExtractorH.h"


ExtractorH::ExtractorH()
{
}


ExtractorH::~ExtractorH()
{
}

Unit ExtractorH::get(Unit& unit, Army& allies, Army& oponents)
{
	return extractorArmy->get(unit, allies, oponents).getHigestUnit(capacity);
}

std::string ExtractorH::getCode()
{
	return std::string("H") + std::to_string(capacity) + extractorArmy->getCode();
}