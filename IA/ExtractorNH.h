#pragma once
#include "Extractor.h"
class ExtractorNH :	public Extractor<UnitSet>
{
public:
	ExtractorNH(char capacity_index, std::string* code);
	~ExtractorNH();
	UnitSet& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode()const;
	static std::string generateRandomCode(int i);
private:
	std::unique_ptr<Extractor<UnitSet>> extractorArmy;
	int nb_entity;
	int capacity;
	UnitSet vector;
};

