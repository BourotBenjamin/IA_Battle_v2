#pragma once
#include "Extractor.h"
class ExtractorL :	public Extractor<Unit>
{
public:
	ExtractorL(char capacity_index, std::string* code);
	~ExtractorL();
	Unit& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode()const;
	static std::string generateRandomCode(int i);
private:
	std::unique_ptr<Extractor<UnitSet>> extractorArmy;
	int capacity;
};

