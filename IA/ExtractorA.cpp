#include "ExtractorA.h"


ExtractorA::ExtractorA()
{
}


ExtractorA::~ExtractorA()
{
}

UnitSet& ExtractorA::get(Unit& unit, Army& allies, Army& oponents)
{
	return allies.getUnitsList();
}

std::string ExtractorA::getCode()
{
	return std::string("A");
}
