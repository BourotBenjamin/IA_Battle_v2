#pragma once
#include "Extractor.h"
class ExtractorL :	public Extractor<Unit>
{
public:
	ExtractorL(char capacity_index, std::string* code);
	~ExtractorL();
	Unit& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
private:
	Extractor<UnitSet>* extractorArmy;
	int capacity;
};

