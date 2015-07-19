#include "ExtractorTH.h"


ExtractorTH::ExtractorTH(char capacity_index, std::string* code)
{
	capacity = capacity_index - '0';
	std::regex regex("([0-9]+)*+");
	std::smatch base_match;
	std::regex_match(*code, base_match, regex);
	std::string seuil_str = base_match[1].str();
	seuil = std::stoi(seuil_str);
	*code = std::string(code->begin() + seuil_str.length(), code->end());
	extractorArmy = (Extractor<UnitSet>*) ExtractorConstructor::create(code);
}


ExtractorTH::~ExtractorTH()
{
}

UnitSet& ExtractorTH::get(Unit& unit, Army& allies, Army& oponents)
{
	UnitSet units = extractorArmy->get(unit, allies, oponents);
	UnitSet vector;
	for each(auto& u in units)
	{
		if (u->getCapacity(capacity)->getValue() > seuil)
			vector.push_back(u);
	}
	return vector;
}

std::string ExtractorTH::getCode()
{
	return std::string("TH") + std::to_string(capacity) + std::to_string(seuil) + extractorArmy->getCode();
}
