#pragma once
#include "Extractor.h"
class ExtractorHD :	public Extractor<Unit>
{
public:
	ExtractorHD(std::string* code);
	~ExtractorHD();
	Unit& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
private:
	Extractor<UnitSet>* extractorArmy;
	Extractor<Point>* extractorPoint;
};

