#include "ExtractorC.h"
#include "ExtractorConstructor.h"


ExtractorC::ExtractorC(char capacity_index, std::string* code)
{
	capacity = capacity_index - '0';
	extractorUnit = std::move(ExtractorConstructor::createUnitExtractor(code));
}


ExtractorC::~ExtractorC()
{
	extractorUnit.release();
}

double& ExtractorC::get(Unit& unit, Army& allies, Army& oponents)
{
	c = extractorUnit->get(unit, allies, oponents).getCapacity(capacity)->getValue();
	return c;
}

std::string ExtractorC::getCode()
{
	return std::string("C") + std::to_string(capacity) + extractorUnit->getCode();
}

std::string ExtractorC::generateRandomCode(int i)
{
	return std::string("C") + std::to_string(rand() % 7) + ExtractorConstructor::generateRandomExtractorCode(i, ExtractorType::UNIT);
}
