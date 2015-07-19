#include "ExtractorNH.h"


ExtractorNH::ExtractorNH(char capacity_index, std::string* code)
{
	capacity = capacity_index - '0';
	std::regex regex("([0-9]+).+");
	std::smatch base_match;
	std::regex_match(*code, base_match, regex);
	std::string nb_entity_str = base_match[1].str();
	nb_entity = std::stoi(nb_entity_str);
	*code = std::string(code->begin() + nb_entity_str.length(), code->end());
	extractorArmy = (Extractor<UnitSet>*) ExtractorConstructor::create(code);
}


ExtractorNH::~ExtractorNH()
{
}

UnitSet& ExtractorNH::get(Unit& unit, Army& allies, Army& oponents)
{
	int capa_index = capacity;
	UnitSet vector = extractorArmy->get(unit, allies, oponents);
	std::sort(vector.begin(), vector.end(), [&capa_index](std::shared_ptr<Unit> a, std::shared_ptr<Unit> b) { return a->getCapacity(capa_index)->getLevel() > b->getCapacity(capa_index)->getLevel(); });
	return UnitSet(vector.begin(), vector.begin() + nb_entity);
}

std::string ExtractorNH::getCode()
{
	return std::string("NH") + std::to_string(capacity) + std::to_string(nb_entity) + extractorArmy->getCode();
}
