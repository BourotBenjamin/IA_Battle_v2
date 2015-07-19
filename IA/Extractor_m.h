#pragma once
#include "Extractor.h"
class Extractor_m :
	public Extractor<double>
{
public:
	Extractor_m(char capacity_index, std::string* code);
	~Extractor_m();
	double& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
private:
	Extractor<UnitSet>* extractorArmy;
	int capacity;
};

