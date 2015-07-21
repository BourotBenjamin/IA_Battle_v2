#include "ExtractorL.h"
#include "ExtractorConstructor.h"


ExtractorL::ExtractorL(char capacity_index, std::string* code)
{
	capacity = capacity_index - '0';
	extractorArmy = std::move(ExtractorConstructor::createArmyExtractor(code));
}


ExtractorL::~ExtractorL()
{
	extractorArmy.release();
}

Unit& ExtractorL::get(Unit& unit, Army& allies, Army& oponents)
{
	double min = FLT_MAX;
	std::shared_ptr<Unit> worst = nullptr;
	UnitSet& units = extractorArmy->get(unit, allies, oponents);
	if (units.size() == 0)
		throw std::invalid_argument("No units");
	for each(auto& u in units)
	{
		if (u->getCapacity(capacity)->getLevel() < min)
			worst = u;
	}
	return (*worst);
}

std::string ExtractorL::getCode()
{
	return std::string("L") + std::to_string(capacity) + extractorArmy->getCode();
}

std::string ExtractorL::generateRandomCode(int i)
{
	return std::string("L") + std::to_string(rand() % 7) + ExtractorConstructor::generateRandomExtractorCode(i, ExtractorType::ARMY);
}
