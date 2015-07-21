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
	static std::string generateRandomCode(int i);
private:
	std::unique_ptr<Extractor<UnitSet>> extractorArmy;
	std::unique_ptr<Extractor<Point>> extractorPoint;
	double min;
};

