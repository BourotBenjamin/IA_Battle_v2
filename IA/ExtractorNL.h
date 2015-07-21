#pragma once
#include "Extractor.h"
class ExtractorNL :	public Extractor<UnitSet>
{
public:
	ExtractorNL(char capacity_index, std::string* code);
	~ExtractorNL();
	UnitSet& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode()const;
	static std::string generateRandomCode(int i);
private:
	std::unique_ptr<Extractor<UnitSet>> extractorArmy;
	int nb_entity;
	int capacity;
	UnitSet vector;
};

