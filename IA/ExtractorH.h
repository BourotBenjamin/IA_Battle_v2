#pragma once
#include "Extractor.h"
class ExtractorH : public Extractor<Unit>
{
public:
	ExtractorH();
	~ExtractorH();
	Unit get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
private:
	Extractor<Army>* extractorArmy;
	int capacity;
};

