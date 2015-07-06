#pragma once
#include "Extractor.h"
class Extractor_aD :
	public Extractor<float>
{
public:
	Extractor_aD();
	~Extractor_aD();
	float& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
private:
	Extractor<std::vector<std::shared_ptr<Unit>>>* extractorArmy;
	Extractor<Point>* extractorPoint;
};

