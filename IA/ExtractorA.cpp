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

std::string ExtractorA::getCode()const
{
	return std::string("A");
}

std::string ExtractorA::generateRandomCode(int i)
{
	return std::string("A");
}
