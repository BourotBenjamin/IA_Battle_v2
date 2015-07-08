#include "ExtractorO.h"


ExtractorO::ExtractorO()
{
}


ExtractorO::~ExtractorO()
{
}

UnitSet& ExtractorO::get(Unit& unit, Army& allies, Army& oponents)
{
	return oponents.getUnitsList();
}

std::string ExtractorO::getCode()
{
	return std::string("O");
}
