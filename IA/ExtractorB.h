#pragma once
#include "Extractor.h"
class ExtractorB :	public Extractor<Point>
{
public:
	ExtractorB();
	~ExtractorB();
	Point get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
private:
	Extractor<std::vector<std::shared_ptr<Unit>>>* extractorArmy;
};

