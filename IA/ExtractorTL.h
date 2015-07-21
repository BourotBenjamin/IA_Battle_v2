#pragma once
#include "Extractor.h"
class ExtractorTL : public Extractor<UnitSet>
{
public:
	ExtractorTL(char capacity_index, std::string* code);
	~ExtractorTL();
	UnitSet& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode()const;
	static std::string generateRandomCode(int i);
private:
	std::unique_ptr<Extractor<UnitSet>> extractorArmy;
	int seuil;
	int capacity;
	UnitSet vector;
};

