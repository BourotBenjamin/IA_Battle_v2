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
	std::string getCode();

private:
	std::shared_ptr<Extractor<float>> extractor1;
	std::shared_ptr<Extractor<float>> extractor2;
	char operand;
	std::unique_ptr<TreeElement> son1;
	std::unique_ptr<TreeElement> son2;
};

