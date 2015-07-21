#pragma once
#include <string>
#include <memory>
#include "Extractor.h"



enum ExtractorType
{
	UNIT,
	POINT_E,
	VALUE, 
	ARMY
};
class ExtractorConstructor
{
public:
	ExtractorConstructor();
	~ExtractorConstructor();
	static std::unique_ptr<Extractor<Unit>> createUnitExtractor(std::string* code);
	static std::unique_ptr<Extractor<Point>> createPointExtractor(std::string* code);
	static std::unique_ptr<Extractor<double>> createValueExtractor(std::string* code);
	static std::unique_ptr<Extractor<UnitSet>> createArmyExtractor(std::string* code);
	static std::string generateRandomExtractorCode(int i, ExtractorType t);
};

