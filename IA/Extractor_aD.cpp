#include "Extractor_aD.h"


Extractor_aD::Extractor_aD()
{
}


Extractor_aD::~Extractor_aD()
{
}

float& Extractor_aD::get(Unit& unit, Army& allies, Army& oponents)
{
	int nb_unit = 0;
	float sum = 0;
	Point p = extractorPoint->get(unit, allies, oponents);
	for each(auto& u in extractorArmy->get(unit, allies, oponents))
	{
		nb_unit++;
		sum += u->getPosition().distance(p);
	}
	sum /= nb_unit;
	return sum;
}

std::string Extractor_aD::getCode()
{
	return std::string("aD") + extractorArmy->getCode() + extractorPoint->getCode();
}
