#pragma once
#include "Extractor.h"
class Extractor_mD :
	public Extractor<double>
{
public:
	Extractor_mD(std::string* code);
	~Extractor_mD();
	double& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
private:
	Extractor<UnitSet>* extractorArmy;
	Extractor<Point>* extractorPoint;
};

