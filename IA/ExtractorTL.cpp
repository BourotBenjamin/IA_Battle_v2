#include "ExtractorTL.h"


ExtractorTL::ExtractorTL()
{
}


ExtractorTL::~ExtractorTL()
{
}

std::vector<std::shared_ptr<Unit>>& ExtractorTL::get(Unit& unit, Army& allies, Army& oponents)
{
	std::vector<std::shared_ptr<Unit>> units = extractorArmy->get(unit, allies, oponents);
	std::vector<std::shared_ptr<Unit>> vector;
	for each(auto& u in units)
	{
		if (u->getCapacity(capacity)->getValue() < seuil)
			vector.push_back(u);
	}
	return vector;
}

std::string ExtractorTL::getCode()
{
	return std::string("TL") + std::to_string(capacity) + std::to_string(seuil) + extractorArmy->getCode();
}
