#include "ExtractorD.h"


ExtractorD::ExtractorD(std::string* code)
{
	extractorPoint = (Extractor<Point>*) ExtractorConstructor::create(code);
}


ExtractorD::~ExtractorD()
{
}

double& ExtractorD::get(Unit& unit, Army& allies, Army& oponents)
{
	double d = extractorUnit->get(unit, allies, oponents).getPosition().distance(extractorPoint->get(unit, allies, oponents));
	return d;
}

std::string ExtractorD::getCode()
{
	return std::string("D") + extractorUnit->getCode() + extractorPoint->getCode();
}
