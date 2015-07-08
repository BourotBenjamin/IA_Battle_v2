#pragma once
#include "Extractor.h"
class ExtractorNLD : public Extractor<UnitSet>
{
public:
	ExtractorNLD(std::string* code);
	~ExtractorNLD();
	UnitSet& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
private:
	Extractor<Point>* extractorPoint;
	Extractor<UnitSet>* extractorArmy;
	int nb_entity;
};

