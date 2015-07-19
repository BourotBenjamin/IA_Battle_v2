#include "Leaf.h"


Leaf::Leaf()
{
}

Leaf::Leaf(std::string* str)
{
	std::regex regex("[AMEN]([^!?]*).*");
	std::smatch base_match;
	std::regex_match(*str, base_match, regex);
	std::string extractor_str = base_match[1].str();
	int l = extractor_str.length();
	char action = str->at(0);
	switch (action)
	{
	case 'M':
	case 'E':
		extractorP = std::shared_ptr<Extractor<Point>>((Extractor<Point>*) ExtractorConstructor::create(&extractor_str));
		break;
	case 'A':
		extractorU = std::shared_ptr<Extractor<Unit>>((Extractor<Unit>*) ExtractorConstructor::create(&extractor_str));
		break;
	}
	*str = std::string(str->begin() + l + 1, str->end());
}


Leaf::~Leaf()
{
}

std::unique_ptr<Action> Leaf::execute(void* u, void* a, void* o)
{
	Unit unit = *((Unit*)u);
	Army allies = *((Army*)a);
	Army oponents = *((Army*)o);
	switch (action)
	{
	case 'M':
		return std::unique_ptr<Action>(new MoveAction(unit, this->extractorP->get(unit, allies, oponents)));
	case 'E':
		return std::unique_ptr<Action>(new MoveAction(unit, this->extractorP->get(unit, allies, oponents))); // TODO ESCAPE
	case 'A':
		return std::unique_ptr<Action>(new ShotAction(unit, this->extractorU->get(unit, allies, oponents)));
	default:
		return std::unique_ptr<Action>(new EmptyAction(unit));
	}
}

std::string Leaf::getCode()
{
	switch (action)
	{
	case 'M':
		return std::string("!M") + extractorP->getCode();
	case 'E':
		return std::string("!E") + extractorP->getCode();
	case 'A':
		return std::string("!A") + extractorU->getCode();
	default:
		return std::string("!N");
	}
}