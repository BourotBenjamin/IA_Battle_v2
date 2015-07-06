#pragma once
#include "Extractor.h"
class ExtractorLD : public Extractor<Unit>
{
public:
	ExtractorLD();
	~ExtractorLD();
	Unit get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
private:
	Extractor<Army>* extractorArmy;
	Extractor<Point>* extractorPoint;
};

