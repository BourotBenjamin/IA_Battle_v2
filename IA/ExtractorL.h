#pragma once
#include "Extractor.h"
class ExtractorL :	public Extractor<Unit>
{
public:
	ExtractorL();
	~ExtractorL();
	Unit get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
private:
	Extractor<Army>* extractorArmy;
	int capacity;
};

