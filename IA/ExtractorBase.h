#pragma once
class ExtractorBase
{
public:
	ExtractorBase();
	~ExtractorBase();
	virtual std::string getCode() = 0;
};

