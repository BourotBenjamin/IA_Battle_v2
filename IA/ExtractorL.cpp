#include "ExtractorL.h"


ExtractorL::ExtractorL()
{
}


ExtractorL::~ExtractorL()
{
}

Unit& ExtractorL::get(Unit& unit, Army& allies, Army& oponents)
{
	float min = FLT_MAX;
	std::shared_ptr<Unit> worst = nullptr;
	for each(auto& u in extractorArmy->get(unit, allies, oponents))
	{
		if (u->getCapacity(capacity)->getLevel() < min)
			worst = u;
	}
	return (*worst);
}

std::string ExtractorL::getCode()
{
	return std::string("L") + std::to_string(capacity) + extractorArmy->getCode();
}

