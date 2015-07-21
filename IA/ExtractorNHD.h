#pragma once
#include "Extractor.h"
class ExtractorNHD : public Extractor<UnitSet>
{
public:
	ExtractorNHD(std::string* code);
	~ExtractorNHD();
	UnitSet& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode()const;
	static std::string generateRandomCode(int i);
private:
	std::unique_ptr<Extractor<Point>> extractorPoint;
	std::unique_ptr<Extractor<UnitSet>> extractorArmy;
	int nb_entity;
	UnitSet vector;
};

