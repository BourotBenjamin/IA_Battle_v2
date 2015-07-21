#pragma once
#include "Extractor.h"
class ExtractorM :
	public Extractor<double>
{
public:
	ExtractorM(char capacity_index, std::string* code);
	~ExtractorM();
	double& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode()const;
	static std::string generateRandomCode(int i);
private:
	std::unique_ptr<Extractor<UnitSet>> extractorArmy;
	int capacity;
	double max;
};

