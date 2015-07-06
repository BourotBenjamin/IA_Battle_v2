#include "ExtractorNLD.h"


ExtractorNLD::ExtractorNLD()
{
}


ExtractorNLD::~ExtractorNLD()
{
}

std::vector<std::shared_ptr<Unit>>& ExtractorNLD::get(Unit& unit, Army& allies, Army& oponents)
{
	Point p = extractorPoint->get(unit, allies, oponents);
	std::vector<std::shared_ptr<Unit>> vector = extractorArmy->get(unit, allies, oponents);
	std::sort(vector.begin(), vector.end(), [&p](std::shared_ptr<Unit> a, std::shared_ptr<Unit> b) { return a->getPosition().distance(p) < b->getPosition().distance(p); });
	return std::vector<std::shared_ptr<Unit>>(vector.begin(), vector.begin() + nb_entity);
}

std::string ExtractorNLD::getCode()
{
	return std::string("NLD") + std::to_string(nb_entity) + extractorArmy->getCode() + extractorPoint->getCode();
}
