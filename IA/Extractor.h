#pragma once
#include "Unit.hpp"
#include "Army.hpp"
#include "ExtractorConstructor.h"
#include <regex>

template<typename T>
class Extractor
{
public:
	Extractor() {};
	~Extractor() {};
	virtual T& get(Unit& unit, Army& allies, Army& oponents) = 0;
	virtual std::string getCode() { return std::string("");  };
};
