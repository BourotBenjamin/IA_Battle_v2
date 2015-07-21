#include "ExtractorTLD.h"
#include "ExtractorConstructor.h"


ExtractorTLD::ExtractorTLD(std::string* code)
{
	std::regex regex("([0-9]+).+");
	std::smatch base_match;
	std::regex_match(*code, base_match, regex);
	std::string seuil_str = base_match[1].str();
	seuil = std::stoi(seuil_str);
	*code = std::string(code->begin() + seuil_str.length(), code->end());
	extractorArmy = std::move(ExtractorConstructor::createArmyExtractor(code));
	extractorPoint = std::move(ExtractorConstructor::createPointExtractor(code));
}


ExtractorTLD::~ExtractorTLD()
{
	extractorArmy.release();
	extractorPoint.release();
}

UnitSet& ExtractorTLD::get(Unit& unit, Army& allies, Army& oponents)
{
	vector.clear();
	Point& p = extractorPoint->get(unit, allies, oponents);
	UnitSet& units = extractorArmy->get(unit, allies, oponents);
	if (units.size() == 0)
		throw std::invalid_argument("No units");
	for each(auto& u in units)
	{
		if (u->getPosition().distance(p) < seuil)
			vector.push_back(u);
	}
	return vector;
}

std::string ExtractorTLD::getCode()
{
	return std::string("TLD") + std::to_string(seuil) + extractorArmy->getCode() + extractorPoint->getCode();
}

std::string ExtractorTLD::generateRandomCode(int i)
{
	return std::string("TLD") + std::to_string(rand() % 7) + ExtractorConstructor::generateRandomExtractorCode(i, ExtractorType::ARMY) + ExtractorConstructor::generateRandomExtractorCode(i, ExtractorType::POINT_E);
}
