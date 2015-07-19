#pragma once
#include "Extractor.h"
class ExtractorNHD : public Extractor<UnitSet>
{
public:
	ExtractorNHD(std::string* code);
	~ExtractorNHD();
	UnitSet& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
private:
	Extractor<Point>* extractorPoint;
	Extractor<UnitSet>* extractorArmy;
	int nb_entity;
};

