#include "ExtractorTHD.h"


ExtractorTHD::ExtractorTHD()
{
}


ExtractorTHD::~ExtractorTHD()
{
}

std::vector<std::shared_ptr<Unit>>& ExtractorTHD::get(Unit& unit, Army& allies, Army& oponents)
{
	std::vector<std::shared_ptr<Unit>> units = extractorArmy->get(unit, allies, oponents);
	Point p = extractorPoint->get(unit, allies, oponents);
	std::vector<std::shared_ptr<Unit>> vector;
	for each(auto& u in units)
	{
		if (u->getPosition().distance(p) > seuil)
			vector.push_back(u);
	}
	return vector;
}

std::string ExtractorTHD::getCode()
{
	return std::string("THD") + std::to_string(seuil) + extractorArmy->getCode() + extractorPoint->getCode();
}
