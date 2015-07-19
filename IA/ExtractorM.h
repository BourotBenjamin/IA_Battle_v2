#pragma once
#include "Extractor.h"
class ExtractorM :
	public Extractor<double>
{
public:
	ExtractorM(char capacity_index, std::string* code);
	~ExtractorM();
	double& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
private:
	Extractor<UnitSet>* extractorArmy;
	int capacity;
};

