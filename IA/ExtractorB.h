#pragma once
#include "Extractor.h"
class ExtractorB :	public Extractor<Point>
{
public:
	ExtractorB(std::string* code);
	~ExtractorB();
	Point& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
private:
	Extractor<UnitSet>* extractorArmy;
};

