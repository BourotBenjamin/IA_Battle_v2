#include "ExtractorNH.h"


ExtractorNH::ExtractorNH()
{
}


ExtractorNH::~ExtractorNH()
{
}

std::vector<std::shared_ptr<Unit>>& ExtractorNH::get(Unit& unit, Army& allies, Army& oponents)
{
	int capa_index = capacity;
	std::vector<std::shared_ptr<Unit>> vector = extractorArmy->get(unit, allies, oponents);
	std::sort(vector.begin(), vector.end(), [&capa_index](std::shared_ptr<Unit> a, std::shared_ptr<Unit> b) { return a->getCapacity(capa_index)->getLevel() > b->getCapacity(capa_index)->getLevel(); });
	return std::vector<std::shared_ptr<Unit>>(vector.begin(), vector.begin() + nb_entity);
}

std::string ExtractorNH::getCode()
{
	return std::string("NH") + std::to_string(capacity) + std::to_string(nb_entity) + extractorArmy->getCode();
}
