#pragma once
#include "Unit.hpp"
#include "Army.hpp"
#include <regex>

template<typename T>
class Extractor
{
public:
	Extractor() {};
	~Extractor() {};
	virtual T& get(Unit& unit, Army& allies, Army& oponents) = 0;
	virtual std::string getCode()const { return std::string(""); };
	static std::string generateRandomCode(int i)  { return std::string(""); };

};
