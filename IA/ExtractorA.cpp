#include "ExtractorA.h"


ExtractorA::ExtractorA()
{
}


ExtractorA::~ExtractorA()
{
}

Army ExtractorA::get(Unit& unit, Army& allies, Army& oponents)
{
	return allies;
}

std::string ExtractorA::getCode()
{
	return std::string("A");
}
