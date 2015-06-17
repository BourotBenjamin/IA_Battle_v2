#pragma once
#include "Extractor.h"
#include "Unit.hpp"
class ExtractorU : public Extractor<Unit>
{
public:
	ExtractorU();
	~ExtractorU();
	Unit get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
};
