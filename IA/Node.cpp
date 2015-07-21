#include "Node.h"
#include "NodeConstructor.h"
#include "ExtractorConstructor.h"


Node::Node()
{
}

Node::Node(std::string* str)
{
	std::regex regex("([^><=]+)([><=])([^!?]+).*");
	std::smatch base_match;
	std::regex_match(*str, base_match, regex);
	std::string extractor1_str = base_match[1].str();
	std::string extractor2_str = base_match[3].str();
	int l = extractor1_str.length() + extractor2_str.length() + 1;
	extractor1 = std::move(ExtractorConstructor::createValueExtractor(&extractor1_str));
	extractor2 = std::move(ExtractorConstructor::createValueExtractor(&extractor2_str));
	operand = base_match[2].str().at(0);
	*str = std::string(str->begin() + l, str->end());
	son1 = std::unique_ptr<TreeElement>((TreeElement*) NodeConstructor::create(str));
	son2 = std::unique_ptr<TreeElement>((TreeElement*) NodeConstructor::create(str));
}


Node::~Node()
{
	extractor1.reset();
	extractor2.reset();
	son1.release();
	son2.release();
}




std::unique_ptr<Action> Node::execute(Unit& unit, Army& allies, Army& oponents)
{

	double& value1 = this->extractor1->get(unit, allies, oponents);
	double& value2 = this->extractor2->get(unit, allies, oponents);
	bool cond = false;
	switch (operand)
	{
	case '<':
		cond = (value1 < value2);
		break;
	case '>':
		cond = (value1 > value2);
		break;
	case '=':
		cond = (value1 == value2);
		break;
	}
	if (cond)
		return this->son1->execute(unit, allies, oponents);
	else
		return this->son2->execute(unit, allies, oponents);
}

std::string Node::getCode()const
{
	return std::string("?") + extractor1->getCode() + std::string(&operand, 1) + extractor2->getCode() + son1->getCode() + son2->getCode();
}

std::string Node::generateRandomCode(int i)
{
	char* operand = "*";
	int operandId = rand() % 3;
	switch (operandId)
	{
	case 0:
		operand = "<";
		break;
	case 1:
		operand = "<";
		break;
	case 2:
		operand = "=";
		break;
	}
	return std::string("?") + ExtractorConstructor::generateRandomExtractorCode(i, ExtractorType::VALUE) + std::string(operand) + ExtractorConstructor::generateRandomExtractorCode(i, ExtractorType::VALUE) + NodeConstructor::generateRandomTreeElementCode(i) + NodeConstructor::generateRandomTreeElementCode(i);
}

std::string Node::getRandomSonCode(int deepness)const
{
	if (deepness == 0)
		return getCode();
	else if (rand() % 2 == 0)
		return son1->getRandomSonCode(deepness - 1);
	else
		return son2->getRandomSonCode(deepness - 1);
}
