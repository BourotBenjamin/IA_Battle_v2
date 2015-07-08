#include "ExtractorM.h"


ExtractorM::ExtractorM(char capacity_index, std::string* code)
{
	capacity = capacity_index - '0';
	extractorArmy = (Extractor<UnitSet>*) ExtractorConstructor::create(code);
}


ExtractorM::~ExtractorM()
{
}

double& ExtractorM::get(Unit& unit, Army& allies, Army& oponents)
{
	double max = -1;
	for each(auto& u in extractorArmy->get(unit, allies, oponents))
	{
		if (u->getCapacity(capacity)->getValue() > max)
			max = u->getCapacity(capacity)->getValue();
	}
	return max;
}

std::string ExtractorM::getCode()
{
	return std::string("M") + std::to_string(capacity) + extractorArmy->getCode();
}
