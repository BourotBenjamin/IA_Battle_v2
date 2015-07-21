#pragma once
#include "Extractor.h"
class ExtractorLD : public Extractor<Unit>
{
public:
	ExtractorLD(std::string* code);
	~ExtractorLD();
	Unit& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
	static std::string generateRandomCode(int i);
private:
	std::unique_ptr<Extractor<UnitSet>> extractorArmy;
	std::unique_ptr<Extractor<Point>> extractorPoint;
};

