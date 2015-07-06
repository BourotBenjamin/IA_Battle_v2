#pragma once
#include "Extractor.h"
class ExtractorA : public Extractor<std::vector<std::shared_ptr<Unit>>>
{
public:
	ExtractorA();
	~ExtractorA();
	std::vector<std::shared_ptr<Unit>> get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
};

