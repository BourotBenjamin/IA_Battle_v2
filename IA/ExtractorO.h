#pragma once
#include "Extractor.h"
class ExtractorO : public Extractor<UnitSet>
{
public:
	ExtractorO();
	~ExtractorO();
	UnitSet& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode()const;
	static std::string generateRandomCode(int i);
};

