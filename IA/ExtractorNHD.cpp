#include "ExtractorNHD.h"


ExtractorNHD::ExtractorNHD()
{
}


ExtractorNHD::~ExtractorNHD()
{
}

std::vector<std::shared_ptr<Unit>> ExtractorNHD::get(Unit& unit, Army& allies, Army& oponents)
{
	Point p = extractorPoint->get(unit, allies, oponents);
	std::vector<std::shared_ptr<Unit>> vector = extractorArmy->get(unit, allies, oponents);
	std::sort(vector.begin(), vector.end(), [&p](std::shared_ptr<Unit> a, std::shared_ptr<Unit> b) { return a->getPosition().distance(p) > b->getPosition().distance(p); });
	return std::vector<std::shared_ptr<Unit>>(vector.begin(), vector.begin() + nb_entity);
}

std::string ExtractorNHD::getCode()
{
	return std::string("NHD") + std::to_string(nb_entity) + extractorArmy->getCode() + extractorPoint->getCode();
}
