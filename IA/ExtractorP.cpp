#include "ExtractorP.h"


ExtractorP::ExtractorP(std::string* code)
{
	extractorUnit = (Extractor<Unit>*) ExtractorConstructor::create(code);
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

