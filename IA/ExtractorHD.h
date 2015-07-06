#pragma once
#include "Extractor.h"
class ExtractorHD :	public Extractor<Unit>
{
public:
	ExtractorHD();
	~ExtractorHD();
	Unit& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
private:
	Extractor<std::vector<std::shared_ptr<Unit>>>* extractorArmy;
	Extractor<Point>* extractorPoint;
};

