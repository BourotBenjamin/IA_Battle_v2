#pragma once
#include "Extractor.h"
class ExtractorL :	public Extractor<Unit>
{
public:
	ExtractorL();
	~ExtractorL();
	Unit& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
private:
	Extractor<std::vector<std::shared_ptr<Unit>>>* extractorArmy;
	int capacity;
};

