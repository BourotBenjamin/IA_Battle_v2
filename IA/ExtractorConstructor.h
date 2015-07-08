#pragma once
#include <string>
class ExtractorConstructor
{
public:
	ExtractorConstructor();
	~ExtractorConstructor();
	static void* create(std::string* code);
};

