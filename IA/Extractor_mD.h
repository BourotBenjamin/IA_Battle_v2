#pragma once
#include "Extractor.h"
class Extractor_mD :
	public Extractor<float>
{
public:
	Extractor_mD();
	~Extractor_mD();
	float get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
private:
	Extractor<std::vector<std::shared_ptr<Unit>>>* extractorArmy;
	Extractor<Point>* extractorPoint;
};

