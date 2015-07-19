#include "NodeConstructor.h"


NodeConstructor::NodeConstructor()
{
}


NodeConstructor::~NodeConstructor()
{
}


void* NodeConstructor::create(std::string* str)
{
	char c = str->at(0);
	*str = std::string(str->begin() + 1, str->end());
	if (c == '!')
	{
		return (void*)new Leaf(str);
	}
	else if (c == '?')
	{
		return (void*)new Node(str);
	}
}
