#include "ExtractorC.h"


ExtractorC::ExtractorC()
{
}


ExtractorC::~ExtractorC()
{
}

float& ExtractorC::get(Unit& unit, Army& allies, Army& oponents)
{
	float c = extractorUnit->get(unit, allies, oponents).getCapacity(capacity)->getValue();
	return c;
}

std::string ExtractorC::getCode()
{
	return std::string("C") + std::to_string(capacity) + extractorUnit->getCode();
}
