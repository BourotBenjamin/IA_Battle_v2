#pragma once
#include "Extractor.h"
class ExtractorNH :	public Extractor<std::vector<std::shared_ptr<Unit>>>
{
public:
	ExtractorNH();
	~ExtractorNH();
	std::vector<std::shared_ptr<Unit>> get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
private:
	Extractor<std::vector<std::shared_ptr<Unit>>>* extractorArmy;
	int nb_entity;
	int capacity;
};

