#include "ExtractorP.h"


ExtractorP::ExtractorP()
{
}


ExtractorP::~ExtractorP()
{
}

Point& ExtractorP::get(Unit& unit, Army& allies, Army& oponents)
{
	return extractorUnit->get(unit, allies, oponents).getPosition();
}

std::string ExtractorP::getCode()
{
	return std::string("P") + extractorUnit->getCode();
}

