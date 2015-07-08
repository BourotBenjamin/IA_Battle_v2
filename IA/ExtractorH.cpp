#include "ExtractorH.h"


ExtractorH::ExtractorH(char capacity_index, std::string* code)
{
	capacity = capacity_index - '0';
	extractorArmy = (Extractor<UnitSet>*) ExtractorConstructor::create(code);
}


ExtractorH::~ExtractorH()
{
}

Unit& ExtractorH::get(Unit& unit, Army& allies, Army& oponents)
{
	float max = -1;
	std::shared_ptr<Unit> best = nullptr;
	for each(auto& u in extractorArmy->get(unit, allies, oponents))
	{
		if (u->getCapacity(capacity)->getLevel() > max)
			best = u;
	}
	return (*best);
}

std::string ExtractorH::getCode()
{
	return std::string("H") + std::to_string(capacity) + extractorArmy->getCode();
}