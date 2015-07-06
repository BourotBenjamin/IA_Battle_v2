#include "ExtractorLD.h"


ExtractorLD::ExtractorLD()
{
}


ExtractorLD::~ExtractorLD()
{
}

Unit ExtractorLD::get(Unit& unit, Army& allies, Army& oponents)
{
	return extractorArmy->get(unit, allies, oponents).getNearestUnit(extractorPoint->get(unit, allies, oponents));
}

std::string ExtractorLD::getCode()
{
	return std::string("LD") + extractorArmy->getCode() + extractorPoint->getCode();
}
