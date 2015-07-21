#pragma once
#include "Extractor.h"
class ExtractorD : public Extractor<double>
{
public:
	ExtractorD(std::string* code);
	~ExtractorD();
	double& get(Unit& unit, Army& allies, Army& oponents);
	std::string getCode();
	static std::string generateRandomCode(int i);
private:
	std::unique_ptr<Extractor<Unit>> extractorUnit;
	std::unique_ptr<Extractor<Point>> extractorPoint;
	double d;
};

