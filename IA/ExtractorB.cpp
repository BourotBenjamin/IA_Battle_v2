#include "ExtractorB.h"


ExtractorB::ExtractorB()
{
}


ExtractorB::~ExtractorB()
{
}

Point ExtractorB::get(Unit& unit, Army& allies, Army& oponents)
{
	int nb_unit = 0;
	float sumX = 0;
	float sumY = 0;
	for each(auto& u in extractorArmy->get(unit, allies, oponents))
	{
		nb_unit++;
		sumX += u->getPosition().getX();
		sumY += u->getPosition().getX();
	}
	return Point(sumX / nb_unit, sumY / nb_unit);
}

std::string ExtractorB::getCode()
{
	return std::string("B") + extractorArmy->getCode();
}