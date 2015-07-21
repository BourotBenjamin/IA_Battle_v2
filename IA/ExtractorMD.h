#pragma once
#include "Extractor.h"
class ExtractorMD :	public Extractor<double>
{
public:
	ExtractorMD(std::string* code);
	~ExtractorMD();
	double& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
	static std::string generateRandomCode(int i);
private:
	std::unique_ptr<Extractor<UnitSet>> extractorArmy;
	std::unique_ptr<Extractor<Point>> extractorPoint;
	double max;
};

