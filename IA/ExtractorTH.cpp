#include "ExtractorTH.h"


ExtractorTH::ExtractorTH()
{
}


ExtractorTH::~ExtractorTH()
{
}

std::vector<std::shared_ptr<Unit>>& ExtractorTH::get(Unit& unit, Army& allies, Army& oponents)
{
	std::vector<std::shared_ptr<Unit>> units = extractorArmy->get(unit, allies, oponents);
	std::vector<std::shared_ptr<Unit>> vector;
	for each(auto& u in units)
	{
		if (u->getCapacity(capacity)->getValue() > seuil)
			vector.push_back(u);
	}
	return vector;
}

std::string ExtractorTH::getCode()
{
	return std::string("TH") + std::to_string(capacity) + std::to_string(seuil) + extractorArmy->getCode();
}
