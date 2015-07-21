#include "ExtractorD.h"
#include "ExtractorConstructor.h"


ExtractorD::ExtractorD(std::string* code)
{
	extractorUnit = std::move(ExtractorConstructor::createUnitExtractor(code));
	extractorPoint = std::move(ExtractorConstructor::createPointExtractor(code));
}


ExtractorD::~ExtractorD()
{
	extractorPoint.release();
	extractorUnit.release();
}

double& ExtractorD::get(Unit& unit, Army& allies, Army& oponents)
{
	d = extractorUnit->get(unit, allies, oponents).getPosition().distance(extractorPoint->get(unit, allies, oponents));
	return d;
}

std::string ExtractorD::getCode()
{
	return std::string("D") + extractorUnit->getCode() + extractorPoint->getCode();
}

std::string ExtractorD::generateRandomCode(int i)
{
	return std::string("D") + ExtractorConstructor::generateRandomExtractorCode(i, ExtractorType::UNIT) + ExtractorConstructor::generateRandomExtractorCode(i, ExtractorType::POINT);
}
