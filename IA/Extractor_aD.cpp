#include "Extractor_aD.h"


Extractor_aD::Extractor_aD(std::string* code)
{
	extractorArmy = (Extractor<UnitSet>*) ExtractorConstructor::create(code);
	extractorPoint = (Extractor<Point>*) ExtractorConstructor::create(code);
}


Extractor_aD::~Extractor_aD()
{
}

double& Extractor_aD::get(Unit& unit, Army& allies, Army& oponents)
{
	int nb_unit = 0;
	double sum = 0;
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
