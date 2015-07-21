#include "ExtractorM.h"
#include "ExtractorConstructor.h"


ExtractorM::ExtractorM(char capacity_index, std::string* code)
{
	capacity = capacity_index - '0';
	extractorArmy = std::move(ExtractorConstructor::createArmyExtractor(code));
}


ExtractorM::~ExtractorM()
{
	extractorArmy.release();
}

double& ExtractorM::get(Unit& unit, Army& allies, Army& oponents)
{
	max = -1;
	UnitSet& units = extractorArmy->get(unit, allies, oponents);
	if (units.size() == 0)
		throw std::invalid_argument("No units");
	for each(auto& u in units)
	{
		if (u->getCapacity(capacity)->getValue() > max)
			max = u->getCapacity(capacity)->getValue();
	}
	return max;
}

std::string ExtractorM::getCode()
{
	return std::string("M") + std::to_string(capacity) + extractorArmy->getCode();
}

std::string ExtractorM::generateRandomCode(int i)
{
	return std::string("M") + std::to_string(rand() % 7) + ExtractorConstructor::generateRandomExtractorCode(i, ExtractorType::ARMY);
}
