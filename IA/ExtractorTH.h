#pragma once
#include "Extractor.h"
class ExtractorTH :	public Extractor<UnitSet>
{
public:
	ExtractorTH(char capacity_index, std::string* code);
	~ExtractorTH();
	UnitSet& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
private:
	Extractor<UnitSet>* extractorArmy;
	int seuil;
	int capacity;
};

