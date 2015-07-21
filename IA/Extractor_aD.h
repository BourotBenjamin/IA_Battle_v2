#pragma once
#include "Extractor.h"
class Extractor_aD :
	public Extractor<double>
{
public:
	Extractor_aD(std::string* code);
	~Extractor_aD();
	double& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode()const;
	static std::string generateRandomCode(int i);
private:
	std::unique_ptr<Extractor<UnitSet>> extractorArmy;
	std::unique_ptr<Extractor<Point>> extractorPoint;
	double sum;
};

