#pragma once
#include "Extractor.h"
class ExtractorC :
	public Extractor<double>
{
public:
	ExtractorC(char capacity_index, std::string* code);
	~ExtractorC();
	double& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
	static std::string generateRandomCode(int i);
private:
	std::unique_ptr<Extractor<Unit>> extractorUnit;
	int capacity;
	double c;
};

