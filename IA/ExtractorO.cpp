#include "ExtractorO.h"


ExtractorO::ExtractorO()
{
}


ExtractorO::~ExtractorO()
{
}

Army ExtractorO::get(Unit& unit, Army& allies, Army& oponents)
{
	return oponents;
}

std::string ExtractorO::getCode()
{
	return std::string("O");
}
