#pragma once
#include "Extractor.h"
class ExtractorA : public Extractor<UnitSet>
{
public:
	ExtractorA();
	~ExtractorA();
	UnitSet& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode()const;
	static std::string generateRandomCode(int i);
};

