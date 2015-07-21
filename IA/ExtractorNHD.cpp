#include "ExtractorNHD.h"
#include "ExtractorConstructor.h"


ExtractorNHD::ExtractorNHD(std::string* code)
{
	std::regex regex("([0-9]+).+");
	std::smatch base_match;
	std::regex_match(*code, base_match, regex);
	std::string nb_entity_str = base_match[1].str();
	nb_entity = std::stoi(nb_entity_str);
	*code = std::string(code->begin() + nb_entity_str.length(), code->end());
	extractorArmy = std::move(ExtractorConstructor::createArmyExtractor(code));
	extractorPoint = std::move(ExtractorConstructor::createPointExtractor(code));
}


ExtractorNHD::~ExtractorNHD()
{
	extractorArmy.release();
	extractorPoint.release();
}

UnitSet& ExtractorNHD::get(Unit& unit, Army& allies, Army& oponents)
{
	unsigned int nb = nb_entity;
	Point& p = extractorPoint->get(unit, allies, oponents);
	vector = extractorArmy->get(unit, allies, oponents);
	if (vector.size() < nb)
		nb = vector.size();
	if (nb == 0)
	{
		vector = UnitSet();
	}
	else
	{
		std::sort(vector.begin(), vector.end(), [&p](std::shared_ptr<Unit> a, std::shared_ptr<Unit> b) { return a->getPosition().distance(p) > b->getPosition().distance(p); });
		vector = UnitSet(vector.begin(), vector.begin() + nb);
	}
	return vector;
}

std::string ExtractorNHD::getCode()
{
	return std::string("NHD") + std::to_string(nb_entity) + extractorArmy->getCode() + extractorPoint->getCode();
}

std::string ExtractorNHD::generateRandomCode(int i)
{
	return std::string("NHD") + std::to_string(rand() % 7) + ExtractorConstructor::generateRandomExtractorCode(i, ExtractorType::ARMY) + ExtractorConstructor::generateRandomExtractorCode(i, ExtractorType::POINT);
}
