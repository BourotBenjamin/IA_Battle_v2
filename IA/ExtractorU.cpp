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

std::string ExtractorU::getCode()const
{
	return std::string("U");
}

std::string ExtractorU::generateRandomCode(int i)
{
	return std::string("U");
}
