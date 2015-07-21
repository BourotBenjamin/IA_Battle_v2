#pragma once
#include "Node.h"
#include "Leaf.h"
class NodeConstructor
{
public:
	NodeConstructor();
	~NodeConstructor();
	static void* create(std::string* str);
	static std::string NodeConstructor::generateRandomTreeElementCode(int i);
};

