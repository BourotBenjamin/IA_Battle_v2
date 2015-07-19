#pragma once
#include "Extractor.h"
class Extractor_aD :
	public Extractor<double>
{
public:
	Extractor_aD(std::string* code);
	~Extractor_aD();
	double& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
private:
	Extractor<UnitSet>* extractorArmy;
	Extractor<Point>* extractorPoint;
};

