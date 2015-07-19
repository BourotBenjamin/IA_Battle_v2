#include "Node.h"
#include "NodeConstructor.h"


Node::Node()
{
}

Node::Node(std::string* str)
{
	std::regex regex("([^><=]+)([><=])([^!?]+).*");
	std::smatch base_match;
	std::regex_match(*str, base_match, regex);
	std::string extractor1_str = base_match[1].str();
	extractor1 = std::shared_ptr<Extractor<float>>((Extractor<float>*) ExtractorConstructor::create(&extractor1_str));
	std::string extractor2_str = base_match[3].str();
	extractor2 = std::shared_ptr<Extractor<float>>((Extractor<float>*) ExtractorConstructor::create(&extractor2_str));
	operand = base_match[2].str().at(0);
	*str = std::string(str->begin() + extractor1_str.length() + extractor2_str.length() + 1, str->end());
	son1 = std::unique_ptr<TreeElement>((TreeElement*) NodeConstructor::create(str));
	son2 = std::unique_ptr<TreeElement>((TreeElement*) NodeConstructor::create(str));
}


Node::~Node()
{
}




std::unique_ptr<Action> Node::execute(Unit& u, Army& a, Army& o)
{
	float value1 = this->extractor1->get(u, a, o);
	float value2 = this->extractor1->get(u, a, o);
	bool cond = false;
	switch (operand)
	{
	case '<':
		cond = (value1 < value2);
	case '>':
		cond = (value1 > value2);
	case '=':
		cond = (value1 = value2);
	}
	if (cond)
		return this->son1->execute(u, a, o);
	else
		return this->son2->execute(u, a, o);
}

std::string Node::getCode()
{
	return std::string("?") + extractor1->getCode() + std::to_string(operand) + extractor2->getCode() + son1->getCode() + son2->getCode();
}