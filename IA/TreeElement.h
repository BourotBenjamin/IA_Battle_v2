#pragma once
#include "Action.hpp"
#include <memory>
#include <string>
class Army;
class Unit;
class TreeElement
{
public:
	TreeElement();
	~TreeElement();
	virtual std::unique_ptr<Action> execute(Unit& u, Army& a, Army& o) = 0;
	virtual std::string getCode()const = 0;
	static std::string generateRandomCode() { return std::string(""); };
	virtual std::string getRandomSonCode(int deepness)const = 0;
};

