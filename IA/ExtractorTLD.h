#pragma once
#include "Extractor.h"
class ExtractorTLD :
	public Extractor<std::vector<std::shared_ptr<Unit>>>
{
public:
	ExtractorTLD();
	~ExtractorTLD();
	std::vector<std::shared_ptr<Unit>>& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
private:
	Extractor<Point>* extractorPoint;
	Extractor<std::vector<std::shared_ptr<Unit>>>* extractorArmy;
	int seuil;
};

