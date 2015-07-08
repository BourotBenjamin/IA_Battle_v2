#include "Extractor_a.h"


Extractor_a::Extractor_a(char capacity_index, std::string* code)
{
	capacity = capacity_index - '0';
	extractorArmy = (Extractor<UnitSet>*) ExtractorConstructor::create(code);
}

Extractor_a::~Extractor_a()
{
}

double& Extractor_a::get(Unit& unit, Army& allies, Army& oponents)
{
	int nb_unit = 0;
	double sum = 0;
	for each(auto& u in extractorArmy->get(unit, allies, oponents))
	{
		nb_unit++;
		sum += u->getCapacity(capacity)->getValue();
	}
	sum = sum / nb_unit;
	return sum;
}

std::string Extractor_a::getCode()
{
	return std::string("a") + std::to_string(capacity) + extractorArmy->getCode();
}
