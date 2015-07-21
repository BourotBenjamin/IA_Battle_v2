#pragma once
#include "TreeElement.h"
#include "Extractor.h"
#include "Action.hpp"
class Node : public TreeElement
{
public:
	Node();
	Node(std::string* str);
	~Node();
	std::unique_ptr<Action> execute(Unit& unit, Army& allies, Army& oponents);
	std::string getCode()const;
	static std::string generateRandomCode(int i);
	std::string getRandomSonCode(int deepness)const;

private:
	std::shared_ptr<Extractor<double>> extractor1;
	std::shared_ptr<Extractor<double>> extractor2;
	char operand;
	std::unique_ptr<TreeElement> son1;
	std::unique_ptr<TreeElement> son2;
};

