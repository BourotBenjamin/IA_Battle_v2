#pragma once
#include "Extractor.h"
class ExtractorNH :	public Extractor<UnitSet>
{
public:
	ExtractorNH(char capacity_index, std::string* code);
	~ExtractorNH();
	UnitSet& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
private:
	Extractor<UnitSet>* extractorArmy;
	int nb_entity;
	int capacity;
};

