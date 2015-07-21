#include "Extractor_aD.h"
#include "ExtractorConstructor.h"


Extractor_aD::Extractor_aD(std::string* code)
{
	extractorArmy = std::move(ExtractorConstructor::createArmyExtractor(code));
	extractorPoint = std::move(ExtractorConstructor::createPointExtractor(code));
}


Extractor_aD::~Extractor_aD()
{
	extractorArmy.release();
}

double& Extractor_aD::get(Unit& unit, Army& allies, Army& oponents)
{
	int nb_unit = 0;
	sum = 0;
	Point& p = extractorPoint->get(unit, allies, oponents);
	UnitSet& units = extractorArmy->get(unit, allies, oponents);
	if (units.size() == 0)
		throw std::invalid_argument("No units");
	for each(auto& u in units)
	{
		nb_unit++;
		sum += u->getPosition().distance(p);
	}
	sum /= nb_unit;
	return sum;
}

std::string Extractor_aD::getCode()
{
	return std::string("aD") + extractorArmy->getCode() + extractorPoint->getCode();
}

std::string Extractor_aD::generateRandomCode(int i)
{
	return std::string("aD") + ExtractorConstructor::generateRandomExtractorCode(i, ExtractorType::ARMY) + ExtractorConstructor::generateRandomExtractorCode(i, ExtractorType::POINT_E);
}