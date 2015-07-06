#pragma once
#include "Extractor.h"
class ExtractorTL : public Extractor<std::vector<std::shared_ptr<Unit>>>
{
public:
	ExtractorTL();
	~ExtractorTL();
	std::vector<std::shared_ptr<Unit>>& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
private:
	Extractor<std::vector<std::shared_ptr<Unit>>>* extractorArmy;
	int seuil;
	int capacity;
};

