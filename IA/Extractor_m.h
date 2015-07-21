#pragma once
#include "Extractor.h"
class Extractor_m :
	public Extractor<double>
{
public:
	Extractor_m(char capacity_index, std::string* code);
	~Extractor_m();
	double& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode()const;
	static std::string generateRandomCode(int i);
private:
	std::unique_ptr<Extractor<UnitSet>> extractorArmy;
	int capacity;
	double min;
};

