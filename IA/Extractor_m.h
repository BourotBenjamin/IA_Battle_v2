#pragma once
#include "Extractor.h"
class Extractor_m :
	public Extractor<float>
{
public:
	Extractor_m();
	~Extractor_m();
	float& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
private:
	Extractor<std::vector<std::shared_ptr<Unit>>>* extractorArmy;
	int capacity;
};

