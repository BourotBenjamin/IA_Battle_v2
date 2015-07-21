#pragma once
#include "Extractor.h"
class ExtractorTH :	public Extractor<UnitSet>
{
public:
	ExtractorTH(char capacity_index, std::string* code);
	~ExtractorTH();
	UnitSet& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
	static std::string generateRandomCode(int i);
private:
	std::unique_ptr<Extractor<UnitSet>> extractorArmy;
	int seuil;
	int capacity;
	UnitSet vector;
};

