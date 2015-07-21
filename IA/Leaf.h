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
	std::unique_ptr<Action> execute(Unit& unit, Army& allies, Army& oponents);
	std::string getCode()const;
	static std::string generateRandomCode();
	std::string getRandomSonCode(int deepness)const;
private:
	char action;
	std::shared_ptr<Extractor<Unit>> extractorU;
	std::shared_ptr<Extractor<Point>> extractorP;
	Point p;
};

