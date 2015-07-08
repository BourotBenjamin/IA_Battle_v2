#include "ExtractorNHD.h"


ExtractorNHD::ExtractorNHD(std::string* code)
{
	std::regex regex("([0-9]+)*+");
	std::smatch base_match;
	std::regex_match(*code, base_match, regex);
	std::string nb_entity_str = base_match[1].str();
	nb_entity = std::stoi(nb_entity_str);
	*code = std::string(code->begin() + nb_entity_str.length(), code->end());
	extractorArmy = (Extractor<UnitSet>*) ExtractorConstructor::create(code);
	extractorPoint = (Extractor<Point>*) ExtractorConstructor::create(code);
}


ExtractorNHD::~ExtractorNHD()
{
}

UnitSet& ExtractorNHD::get(Unit& unit, Army& allies, Army& oponents)
{
	Point p = extractorPoint->get(unit, allies, oponents);
	UnitSet vector = extractorArmy->get(unit, allies, oponents);
	std::sort(vector.begin(), vector.end(), [&p](std::shared_ptr<Unit> a, std::shared_ptr<Unit> b) { return a->getPosition().distance(p) > b->getPosition().distance(p); });
	return UnitSet(vector.begin(), vector.begin() + nb_entity);
}

std::string ExtractorNHD::getCode()
{
	return std::string("NHD") + std::to_string(nb_entity) + extractorArmy->getCode() + extractorPoint->getCode();
}
