#include "ExtractorNL.h"
#include "ExtractorConstructor.h"


ExtractorNL::ExtractorNL(char capacity_index, std::string* code)
{
	capacity = capacity_index - '0';
	std::regex regex("([0-9]+).+");
	std::smatch base_match;
	std::regex_match(*code, base_match, regex);
	std::string nb_entity_str = base_match[1].str();
	nb_entity = std::stoi(nb_entity_str);
	*code = std::string(code->begin() + nb_entity_str.length(), code->end());
	extractorArmy = std::move(ExtractorConstructor::createArmyExtractor(code));
}


ExtractorNL::~ExtractorNL()
{
	extractorArmy.release();
}

UnitSet& ExtractorNL::get(Unit& unit, Army& allies, Army& oponents)
{
	unsigned int nb = nb_entity;
	int capa_index = capacity;
	vector = extractorArmy->get(unit, allies, oponents);	
	if (vector.size() < nb)
		nb = vector.size();
	if (nb == 0)
	{
		vector = UnitSet();
	}
	else
	{
		std::sort(vector.begin(), vector.end(), [&capa_index](std::shared_ptr<Unit> a, std::shared_ptr<Unit> b) { return a->getCapacity(capa_index)->getLevel() < b->getCapacity(capa_index)->getLevel(); });
		vector = UnitSet(vector.begin(), vector.begin() + nb);
	}
	return vector;
}

std::string ExtractorNL::getCode()
{
	return std::string("NL") + std::to_string(capacity) + std::to_string(nb_entity) + extractorArmy->getCode();
}

std::string ExtractorNL::generateRandomCode(int i)
{
	return std::string("NL") + std::to_string(rand() % 7) + std::to_string(rand() % 10) + ExtractorConstructor::generateRandomExtractorCode(i, ExtractorType::ARMY);
}