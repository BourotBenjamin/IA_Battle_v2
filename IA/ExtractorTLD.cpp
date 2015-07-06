#include "ExtractorTLD.h"


ExtractorTLD::ExtractorTLD()
{
}


ExtractorTLD::~ExtractorTLD()
{
}

std::vector<std::shared_ptr<Unit>> ExtractorTLD::get(Unit& unit, Army& allies, Army& oponents)
{
	std::vector<std::shared_ptr<Unit>> units = extractorArmy->get(unit, allies, oponents);
	Point p = extractorPoint->get(unit, allies, oponents);
	std::vector<std::shared_ptr<Unit>> vector;
	for each(auto& u in units)
	{
		if (u->getPosition().distance(p) < seuil)
			vector.push_back(u);
	}
	return vector;
}

std::string ExtractorTLD::getCode()
{
	return std::string("TLD") + std::to_string(seuil) + extractorArmy->getCode() + extractorPoint->getCode();
}
