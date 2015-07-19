#include "ExtractorC.h"


ExtractorC::ExtractorC(char capacity_index, std::string* code)
{
	capacity = capacity_index - '0';
	extractorUnit = (Extractor<Unit>*) ExtractorConstructor::create(code);
}


ExtractorC::~ExtractorC()
{
}

double& ExtractorC::get(Unit& unit, Army& allies, Army& oponents)
{
	double c = extractorUnit->get(unit, allies, oponents).getCapacity(capacity)->getValue();
	return c;
}

std::string ExtractorC::getCode()
{
	return std::string("C") + std::to_string(capacity) + extractorUnit->getCode();
}
