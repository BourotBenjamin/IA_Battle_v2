#include "ExtractorHD.h"


ExtractorHD::ExtractorHD()
{
}


ExtractorHD::~ExtractorHD()
{
}

Unit ExtractorHD::get(Unit& unit, Army& allies, Army& oponents)
{
	return extractorArmy->get(unit, allies, oponents).getFurthestUnit(extractorPoint->get(unit, allies, oponents));
}

std::string ExtractorHD::getCode()
{
	return std::string("HD") + extractorArmy->getCode() + extractorPoint->getCode();
}
