#pragma once
#include "Extractor.h"
class Extractor_a :
	public Extractor<float>
{
public:
	Extractor_a();
	~Extractor_a();
	float get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
private:
	Extractor<std::vector<std::shared_ptr<Unit>>>* extractorArmy;
	int capacity;
};

