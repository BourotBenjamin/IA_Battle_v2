#include "ExtractorH.h"
#include "ExtractorConstructor.h"


ExtractorH::ExtractorH(char capacity_index, std::string* code)
{
	capacity = capacity_index - '0';
	extractorArmy = std::move(ExtractorConstructor::createArmyExtractor(code));
}


ExtractorH::~ExtractorH()
{
	extractorArmy.release();
}

Unit& ExtractorH::get(Unit& unit, Army& allies, Army& oponents)
{
	double max = -1;
	std::shared_ptr<Unit> best = nullptr;
	UnitSet& units = extractorArmy->get(unit, allies, oponents);
	if (units.size() == 0)
		throw std::invalid_argument("No units");
	for each(auto& u in units)
	{
		if (u->getCapacity(capacity)->getLevel() > max)
			best = u;
	}
	return (*best);
}

std::string ExtractorH::getCode()
{
	return std::string("H") + std::to_string(capacity) + extractorArmy->getCode();
}

std::string ExtractorH::generateRandomCode(int i)
{
	return std::string("H") + std::to_string(rand() % 7) + ExtractorConstructor::generateRandomExtractorCode(i, ExtractorType::ARMY);
}