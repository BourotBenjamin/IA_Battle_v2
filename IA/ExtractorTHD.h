#pragma once
#include "Extractor.h"
class ExtractorTHD :
	public Extractor<std::vector<std::shared_ptr<Unit>>>
{
public:
	ExtractorTHD();
	~ExtractorTHD();
	std::vector<std::shared_ptr<Unit>> get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
private:
	Extractor<Point>* extractorPoint;
	Extractor<std::vector<std::shared_ptr<Unit>>>* extractorArmy;
	int seuil;
};

