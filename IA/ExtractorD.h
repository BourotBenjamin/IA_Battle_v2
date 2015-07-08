#pragma once
#include "Extractor.h"
class ExtractorD : public Extractor<double>
{
public:
	ExtractorD(std::string* code);
	~ExtractorD();
	double& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
private:
	Extractor<Unit>* extractorUnit;
	Extractor<Point>* extractorPoint;
};

