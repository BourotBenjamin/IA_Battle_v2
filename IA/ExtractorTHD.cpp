#include "ExtractorTHD.h"
#include "ExtractorConstructor.h"

ExtractorTHD::ExtractorTHD(std::string* code)
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


ExtractorTHD::~ExtractorTHD()
{
	extractorArmy.release();
	extractorPoint.release();
}

UnitSet& ExtractorTHD::get(Unit& unit, Army& allies, Army& oponents)
{
	vector.clear();
	Point& p = extractorPoint->get(unit, allies, oponents);
	UnitSet& units = extractorArmy->get(unit, allies, oponents);
	if (units.size() == 0)
		throw std::invalid_argument("No units");
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

std::string ExtractorTHD::generateRandomCode(int i)
{
	return std::string("THD") + std::to_string(rand() % 7) + ExtractorConstructor::generateRandomExtractorCode(i, ExtractorType::ARMY) + ExtractorConstructor::generateRandomExtractorCode(i, ExtractorType::POINT_E);
}
