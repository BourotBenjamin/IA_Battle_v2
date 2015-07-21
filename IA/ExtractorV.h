#pragma once
#include "Extractor.h"
class ExtractorV : public Extractor<double>
{
public:
	ExtractorV(std::string* code);
	~ExtractorV();
	double& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode()const;
	static std::string generateRandomCode(int i);
private:
	double value;
};

