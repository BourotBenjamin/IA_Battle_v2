#include "ExtractorV.h"
#include "ExtractorConstructor.h"


ExtractorV::ExtractorV(std::string* code)
{
	value = std::stod(*code);
}


ExtractorV::~ExtractorV()
{
}

double& ExtractorV::get(Unit& unit, Army& allies, Army& oponents)
{
	return value;
}

std::string ExtractorV::getCode()const
{
	return std::string("V") + std::to_string(value);
}

std::string ExtractorV::generateRandomCode(int i)
{
	return std::string("V") + std::to_string((rand() % 20000) / 1000.0);
}
