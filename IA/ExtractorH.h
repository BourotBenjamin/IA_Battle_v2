#pragma once
#include "Extractor.h"
class ExtractorH : public Extractor<Unit>
{
public:
	ExtractorH(char capacity_index, std::string* code);
	~ExtractorH();
	Unit& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode()const;
	static std::string generateRandomCode(int i);
private:
	std::unique_ptr<Extractor<UnitSet>> extractorArmy;
	int capacity;
};

