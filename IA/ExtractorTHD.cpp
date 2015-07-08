#include "ExtractorTHD.h"


ExtractorTHD::ExtractorTHD(std::string* code)
{
	std::regex regex("([0-9]+)*+");
	std::smatch base_match;
	std::regex_match(*code, base_match, regex);
	std::string seuil_str = base_match[1].str();
	seuil = std::stoi(seuil_str);
	*code = std::string(code->begin() + seuil_str.length(), code->end());
	extractorArmy = (Extractor<UnitSet>*) ExtractorConstructor::create(code);
	extractorPoint = (Extractor<Point>*) ExtractorConstructor::create(code);
}


ExtractorTHD::~ExtractorTHD()
{
}

UnitSet& ExtractorTHD::get(Unit& unit, Army& allies, Army& oponents)
{
	UnitSet units = extractorArmy->get(unit, allies, oponents);
	Point p = extractorPoint->get(unit, allies, oponents);
	UnitSet vector;
	for each(auto& u in units)
	{
		if (u->getPosition().distance(p) > seuil)
			vector.push_back(u);
	}
	return vector;
}

std::string ExtractorTHD::getCode()
{
	return std::string("THD") + std::to_string(seuil) + extractorArmy->getCode() + extractorPoint->getCode();
}
