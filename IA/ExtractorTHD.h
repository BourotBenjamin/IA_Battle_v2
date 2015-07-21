#pragma once
#include "Extractor.h"
class ExtractorTHD :
	public Extractor<UnitSet>
{
public:
	ExtractorTHD(std::string* code);
	~ExtractorTHD();
	UnitSet& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode()const;
	static std::string generateRandomCode(int i);
private:
	std::unique_ptr<Extractor<Point>> extractorPoint;
	std::unique_ptr<Extractor<UnitSet>> extractorArmy;
	int seuil;
	UnitSet vector;
};

