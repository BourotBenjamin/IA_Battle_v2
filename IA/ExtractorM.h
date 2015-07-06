#pragma once
#include "Extractor.h"
class ExtractorM :
	public Extractor<float>
{
public:
	ExtractorM();
	~ExtractorM();
	float& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
private:
	Extractor<std::vector<std::shared_ptr<Unit>>>* extractorArmy;
	int capacity;
};

