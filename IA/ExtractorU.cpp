#include "ExtractorU.h"


ExtractorU::ExtractorU()
{
}


ExtractorU::~ExtractorU()
{
}


Unit& ExtractorU::get(Unit& unit, Army& allies, Army& oponents)
{
	return unit;
}

std::string ExtractorU::getCode()
{
	return std::string("U");
}
