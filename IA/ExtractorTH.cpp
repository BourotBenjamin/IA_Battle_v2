#include "ExtractorTH.h"
#include "ExtractorConstructor.h"


ExtractorTH::ExtractorTH(char capacity_index, std::string* code)
{
	capacity = capacity_index - '0';
	std::regex regex("([0-9]+).+");
	std::smatch base_match;
	std::regex_match(*code, base_match, regex);
	std::string seuil_str = base_match[1].str();
	seuil = std::stoi(seuil_str);
	*code = std::string(code->begin() + seuil_str.length(), code->end());
	extractorArmy = std::move(ExtractorConstructor::createArmyExtractor(code));
}


ExtractorTH::~ExtractorTH()
{
	extractorArmy.release();
}

UnitSet& ExtractorTH::get(Unit& unit, Army& allies, Army& oponents)
{
	vector.clear();
	UnitSet& units = extractorArmy->get(unit, allies, oponents);
	if (units.size() == 0)
		throw std::invalid_argument("No units");
	for each(auto& u in units)
	{
		if (u->getCapacity(capacity)->getValue() > seuil)
			vector.push_back(u);
	}
	return vector;
}

std::string ExtractorTH::getCode()const
{
	return std::string("TH") + std::to_string(capacity) + std::to_string(seuil) + extractorArmy->getCode();
}

std::string ExtractorTH::generateRandomCode(int i)
{
	return std::string("TH") + std::to_string(rand() % 7) + std::to_string(rand() % 50) + ExtractorConstructor::generateRandomExtractorCode(i, ExtractorType::ARMY);
}
