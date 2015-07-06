#pragma once
#include "Extractor.h"
class ExtractorNHD : public Extractor<std::vector<std::shared_ptr<Unit>>>
{
public:
	ExtractorNHD();
	~ExtractorNHD();
	std::vector<std::shared_ptr<Unit>>& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
private:
	Extractor<Point>* extractorPoint;
	Extractor<std::vector<std::shared_ptr<Unit>>>* extractorArmy;
	int nb_entity;
};

