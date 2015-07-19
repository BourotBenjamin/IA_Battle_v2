#pragma once
#include "Action.hpp"
#include <memory>
#include <string>
class TreeElement
{
public:
	TreeElement();
	~TreeElement();
	virtual std::unique_ptr<Action> execute(void* u, void* a, void* o) = 0;
	virtual std::string getCode() = 0;
};

