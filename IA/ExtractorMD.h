#pragma once
#include "Extractor.h"
class ExtractorMD :	public Extractor<double>
{
public:
	ExtractorMD(std::string* code);
	~ExtractorMD();
	double& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
private:
	Extractor<UnitSet>* extractorArmy;
	Extractor<Point>* extractorPoint;
};

