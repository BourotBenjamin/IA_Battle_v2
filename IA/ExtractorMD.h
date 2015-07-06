#pragma once
#include "Extractor.h"
class ExtractorMD :	public Extractor<float>
{
public:
	ExtractorMD();
	~ExtractorMD();
	float get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
private:
	Extractor<std::vector<std::shared_ptr<Unit>>>* extractorArmy;
	Extractor<Point>* extractorPoint;
};

