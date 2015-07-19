#pragma once
#include "TreeElement.h"
#include "Extractor.h"
#include "ShotAction.hpp"
#include "EmptyAction.hpp"
#include "MoveAction.hpp"
class Leaf :
	public TreeElement
{
public:
	Leaf();
	Leaf(std::string*);
	~Leaf();
	std::unique_ptr<Action> execute(Unit& u, Army& a, Army& o);
	std::string getCode();
private:
	char action;
	std::shared_ptr<Extractor<Unit>> extractorU;
	std::shared_ptr<Extractor<Point>> extractorP;
};

