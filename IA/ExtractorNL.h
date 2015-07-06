#pragma once
#include "Extractor.h"
class ExtractorNL :	public Extractor<std::vector<std::shared_ptr<Unit>>>
{
public:
	ExtractorNL();
	~ExtractorNL();
	std::vector<std::shared_ptr<Unit>>& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
private:
	Extractor<std::vector<std::shared_ptr<Unit>>>* extractorArmy;
	int nb_entity;
	int capacity;
};

