#pragma once
#include "Extractor.h"
class ExtractorTHD :
	public Extractor<UnitSet>
{
public:
	ExtractorTHD(std::string* code);
	~ExtractorTHD();
	UnitSet& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
private:
	Extractor<Point>* extractorPoint;
	Extractor<UnitSet>* extractorArmy;
	int seuil;
};

