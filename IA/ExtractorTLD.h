#pragma once
#include "Extractor.h"
class ExtractorTLD :
	public Extractor<UnitSet>
{
public:
	ExtractorTLD(std::string* code);
	~ExtractorTLD();
	UnitSet& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode()const;
	static std::string generateRandomCode(int i);
private:
	std::unique_ptr<Extractor<Point>> extractorPoint;
	std::unique_ptr<Extractor<UnitSet>> extractorArmy;
	int seuil;
	UnitSet vector;
};

