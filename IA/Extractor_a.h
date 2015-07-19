#pragma once
#include "Extractor.h"
class Extractor_a :
	public Extractor<double>
{
public:
	Extractor_a(char capacity_index, std::string* code);
	~Extractor_a();
	double& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
private:
	Extractor<UnitSet>* extractorArmy;
	int capacity;
};

