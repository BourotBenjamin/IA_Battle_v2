#pragma once
#include "Extractor.h"
class ExtractorTLD :
	public Extractor<UnitSet>
{
public:
	ExtractorTLD(std::string* code);
	~ExtractorTLD();
	UnitSet& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
private:
	Extractor<Point>* extractorPoint;
	Extractor<UnitSet>* extractorArmy;
	int seuil;
};

