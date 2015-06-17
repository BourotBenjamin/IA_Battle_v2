#include "ExtractorD.h"


ExtractorD::ExtractorD()
{
}


ExtractorD::~ExtractorD()
{
}

float ExtractorD::get(Unit& unit, Army& allies, Army& oponents)
{
	return extractorUnit->get(unit, allies, oponents).getPosition().distance(extractorPoint->get(unit, allies, oponents));
}

std::string ExtractorD::getCode()
{
	return std::string("D") + extractorUnit->getCode() + extractorPoint->getCode();
}
