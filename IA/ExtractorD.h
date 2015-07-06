#pragma once
#include "Extractor.h"
class ExtractorD :
	public Extractor<float>
{
public:
	ExtractorD();
	~ExtractorD();
	float& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
private:
	Extractor<Unit>* extractorUnit;
	Extractor<Point>* extractorPoint;
};

