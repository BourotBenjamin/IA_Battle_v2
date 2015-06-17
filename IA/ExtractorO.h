#pragma once
#include "Extractor.h"
class ExtractorO :
	public Extractor<Army>
{
public:
	ExtractorO();
	~ExtractorO();
	Army get(Unit& unit, Army& allies, Army& oponents);
};

