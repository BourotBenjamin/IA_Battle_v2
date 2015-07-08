#pragma once
#include "Extractor.h"
class ExtractorP :
	public Extractor<Point>
{
public:
	ExtractorP(std::string* code);
	~ExtractorP();
	Point& get(Unit& unit, Army& allies, Army& oponents);
	std::string ExtractorP::getCode();
private:
	Extractor<Unit>* extractorUnit;
};

