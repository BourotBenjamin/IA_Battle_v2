#pragma once
#include "Extractor.h"
class ExtractorHD :	public Extractor<Unit>
{
public:
	ExtractorHD(std::string* code);
	~ExtractorHD();
	Unit& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode()const;
	static std::string generateRandomCode(int i);
private:
	std::unique_ptr<Extractor<UnitSet>> extractorArmy;
	std::unique_ptr<Extractor<Point>> extractorPoint;
};

