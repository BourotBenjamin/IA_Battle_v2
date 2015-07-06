#pragma once
#include "Extractor.h"
class ExtractorTH :	public Extractor<std::vector<std::shared_ptr<Unit>>>
{
public:
	ExtractorTH();
	~ExtractorTH();
	std::vector<std::shared_ptr<Unit>> get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
private:
	Extractor<std::vector<std::shared_ptr<Unit>>>* extractorArmy;
	int seuil;
	int capacity;
};

