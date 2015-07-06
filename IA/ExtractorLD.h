#pragma once
#include "Extractor.h"
class ExtractorLD : public Extractor<Unit>
{
public:
	ExtractorLD();
	~ExtractorLD();
	Unit get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
private:
	Extractor<std::vector<std::shared_ptr<Unit>>>* extractorArmy;
	Extractor<Point>* extractorPoint;
};

