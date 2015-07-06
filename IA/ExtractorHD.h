#pragma once
#include "Extractor.h"
class ExtractorHD :	public Extractor<Unit>
{
public:
	ExtractorHD();
	~ExtractorHD();
	Unit get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
private:
	Extractor<Army>* extractorArmy;
	Extractor<Point>* extractorPoint;
};

