#include "Extractor_m.h"
#include "ExtractorConstructor.h"


Extractor_m::Extractor_m(char capacity_index, std::string* code)
{
	capacity = capacity_index - '0';
	extractorArmy = std::move(ExtractorConstructor::createArmyExtractor(code));
}


Extractor_m::~Extractor_m()
{
	extractorArmy.release();
}

double& Extractor_m::get(Unit& unit, Army& allies, Army& oponents)
{
	min = DBL_MAX;
	UnitSet& units = extractorArmy->get(unit, allies, oponents);
	if (units.size() == 0)
		throw std::invalid_argument("No units");
	for each(auto& u in units)
	{
		if (u->getCapacity(capacity)->getValue() < min)
			min = u->getCapacity(capacity)->getValue();
	}
	return min;
}

std::string Extractor_m::getCode()const
{
	return std::string("m") + std::to_string(capacity) + extractorArmy->getCode();
}

std::string Extractor_m::generateRandomCode(int i)
{
	return std::string("m") + std::to_string(rand() % 7) + ExtractorConstructor::generateRandomExtractorCode(i, ExtractorType::ARMY);
}
