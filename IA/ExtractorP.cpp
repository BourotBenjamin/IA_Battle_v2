#include "ExtractorP.h"
#include "ExtractorConstructor.h"


ExtractorP::ExtractorP(std::string* code)
{
	extractorUnit = std::move(ExtractorConstructor::createUnitExtractor(code));
}


ExtractorP::~ExtractorP()
{
	extractorUnit.release();
}

Point& ExtractorP::get(Unit& unit, Army& allies, Army& oponents)
{
	return extractorUnit->get(unit, allies, oponents).getPosition();
}

std::string ExtractorP::getCode()
{
	return std::string("P") + extractorUnit->getCode();
}

std::string ExtractorP::generateRandomCode(int i)
{
	return std::string("P") + ExtractorConstructor::generateRandomExtractorCode(i, ExtractorType::UNIT);
}

