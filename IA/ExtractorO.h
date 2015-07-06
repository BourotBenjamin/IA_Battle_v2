#pragma once
#include "Extractor.h"
class ExtractorO : public Extractor<std::vector<std::shared_ptr<Unit>>>
{
public:
	ExtractorO();
	~ExtractorO();
	std::vector<std::shared_ptr<Unit>>& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
};

