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
	char action = str->at(0);
	switch (action)
	{
	case 'M':
	case 'E':
		extractorP = std::shared_ptr<Extractor<Point>>((Extractor<Point>*) ExtractorConstructor::create(&extractor_str));
	case 'A':
		extractorU = std::shared_ptr<Extractor<Unit>>((Extractor<Unit>*) ExtractorConstructor::create(&extractor_str));
	}
	*str = std::string(str->begin() + extractor_str.length() + 1, str->end());
}


Leaf::~Leaf()
{
}

std::unique_ptr<Action> Leaf::execute(Unit& u, Army& a, Army& o)
{
	switch (action)
	{
	case 'M':
		return std::unique_ptr<Action>(new MoveAction(u, this->extractorP->get(u, a, o)));
	case 'E':
		return std::unique_ptr<Action>(new MoveAction(u, this->extractorP->get(u, a, o))); // TODO ESCAPE
	case 'A':
		return std::unique_ptr<Action>(new ShotAction(u, this->extractorU->get(u, a, o)));
	default:
		return std::unique_ptr<Action>(new EmptyAction(u));
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