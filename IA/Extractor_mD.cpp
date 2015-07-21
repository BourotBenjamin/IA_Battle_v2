#include "Extractor_mD.h"
#include "ExtractorConstructor.h"


Extractor_mD::Extractor_mD(std::string* code)
{
	extractorArmy = std::move(ExtractorConstructor::createArmyExtractor(code));
	extractorPoint = std::move(ExtractorConstructor::createPointExtractor(code));
}


Extractor_mD::~Extractor_mD()
{
	extractorArmy.release();
	extractorPoint.release();
}

double& Extractor_mD::get(Unit& unit, Army& allies, Army& oponents)
{
	min = DBL_MAX;
	Point& p = extractorPoint->get(unit, allies, oponents);
	UnitSet& units = extractorArmy->get(unit, allies, oponents);
	if (units.size() == 0)
		throw std::invalid_argument("No units");
	for each(auto& u in units)
	{
		double dist = u->getPosition().distance(p);
		if (dist < min)
			min = dist;
	}
	return min;
}

std::string Extractor_mD::getCode()
{
	return std::string("mD") + extractorArmy->getCode() + extractorPoint->getCode();
}

std::string Extractor_mD::generateRandomCode(int i)
{
	return std::string("mD") + ExtractorConstructor::generateRandomExtractorCode(i, ExtractorType::ARMY) + ExtractorConstructor::generateRandomExtractorCode(i, ExtractorType::POINT_E);
}