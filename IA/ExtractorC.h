#pragma once
#include "Extractor.h"
class ExtractorC :
	public Extractor<float>
{
public:
	ExtractorC();
	~ExtractorC();
	float& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
private:
	Extractor<Unit>* extractorUnit;
	int capacity;
};

