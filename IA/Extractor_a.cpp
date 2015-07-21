#include "Extractor_a.h"
#include "ExtractorConstructor.h"


Extractor_a::Extractor_a(char capacity_index, std::string* code)
{
	capacity = capacity_index - '0';
	extractorArmy = std::move(ExtractorConstructor::createArmyExtractor(code));
}

Extractor_a::~Extractor_a()
{
	extractorArmy.release();
}

double& Extractor_a::get(Unit& unit, Army& allies, Army& oponents)
{
	int nb_unit = 0;
	sum = 0;
	UnitSet& units = extractorArmy->get(unit, allies, oponents);
	if (units.size() == 0)
		throw std::invalid_argument("No units");
	for each(auto& u in units)
	{
		nb_unit++;
		sum += u->getCapacity(capacity)->getValue();
	}
	sum = sum / nb_unit;
	return sum;
}

std::string Extractor_a::getCode()const
{
	return std::string("a") + std::to_string(capacity) + extractorArmy->getCode();
}

std::string Extractor_a::generateRandomCode(int i)
{ 
	return std::string("a") + std::to_string(rand() % 7) + ExtractorConstructor::generateRandomExtractorCode(i, ExtractorType::ARMY);
}