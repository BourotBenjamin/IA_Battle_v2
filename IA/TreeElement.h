#pragma once
#include "Action.hpp"
#include "Army.hpp"
#include "Unit.hpp"
class TreeElement
{
public:
	TreeElement();
	~TreeElement();
	virtual std::unique_ptr<Action> execute(Unit& u, Army& a, Army& o) = 0;
	virtual std::string getCode() = 0;
};

