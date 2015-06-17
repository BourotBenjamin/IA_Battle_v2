#include "ExtractorC.h"


ExtractorC::ExtractorC()
{
}


ExtractorC::~ExtractorC()
{
}

float ExtractorC::get(Unit& unit, Army& allies, Army& oponents)
{
	return extractorUnit->get(unit, allies, oponents).getCapacity(capacity)->getValue();
}

std::string ExtractorC::getCode()
{
	return std::string("C") + std::to_string(capacity) + extractorUnit->getCode();
}
