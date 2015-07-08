#include "Extractor_m.h"


Extractor_m::Extractor_m(char capacity_index, std::string* code)
{
	capacity = capacity_index - '0';
	extractorArmy = (Extractor<UnitSet>*) ExtractorConstructor::create(code);
}


Extractor_m::~Extractor_m()
{
}

double& Extractor_m::get(Unit& unit, Army& allies, Army& oponents)
{
	double min = DBL_MAX;
	for each(auto& u in extractorArmy->get(unit, allies, oponents))
	{
		if (u->getCapacity(capacity)->getValue() < min)
			min = u->getCapacity(capacity)->getValue();
	}
	return min;
}

std::string Extractor_m::getCode()
{
	return std::string("M") + std::to_string(capacity) + extractorArmy->getCode();
}
