#pragma once
#include "Extractor.h"
class ExtractorA :
	public Extractor<Army>
{
public:
	ExtractorA();
	~ExtractorA();
	Army get(Unit& unit, Army& allies, Army& oponents);
};

