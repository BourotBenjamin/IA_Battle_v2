#pragma once
#include "Extractor.h"
class ExtractorLD : public Extractor<Unit>
{
public:
	ExtractorLD(std::string* code);
	~ExtractorLD();
	Unit& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
private:
	Extractor<UnitSet>* extractorArmy;
	Extractor<Point>* extractorPoint;
};

