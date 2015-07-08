#pragma once
#include "Extractor.h"
class ExtractorC :
	public Extractor<double>
{
public:
	ExtractorC(std::string* code);
	~ExtractorC();
	double& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
private:
	Extractor<Unit>* extractorUnit;
	int capacity;
};

