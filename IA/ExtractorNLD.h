#pragma once
#include "Extractor.h"
class ExtractorNLD : public Extractor<UnitSet>
{
public:
	ExtractorNLD(std::string* code);
	~ExtractorNLD();
	UnitSet& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
	static std::string generateRandomCode(int i);
private:
	std::unique_ptr<Extractor<Point>> extractorPoint;
	std::unique_ptr<Extractor<UnitSet>> extractorArmy;
	int nb_entity;
	UnitSet vector;
};

