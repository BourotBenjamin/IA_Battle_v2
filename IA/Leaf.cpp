#include "Leaf.h"
#include "ExtractorConstructor.h"


Leaf::Leaf(std::string* str)
{
	std::regex regex("[AMEN]([^!?]*).*");
	std::smatch base_match;
	std::regex_match(*str, base_match, regex);
	std::string extractor_str = base_match[1].str();
	int l = extractor_str.length();
	action = str->at(0);
	switch (action)
	{
	case 'M':
	case 'E':
		extractorP = std::move(ExtractorConstructor::createPointExtractor(&extractor_str));
		break;
	case 'A':
		extractorU = std::move(ExtractorConstructor::createUnitExtractor(&extractor_str));
		break;
	}
	*str = std::string(str->begin() + l + 1, str->end());
}


Leaf::~Leaf()
{
	extractorP.reset();
	extractorU.reset();
}

std::unique_ptr<Action> Leaf::execute(Unit& unit, Army& allies, Army& oponents)
{
	switch (action)
	{
	case 'M':
		return std::unique_ptr<Action>(new MoveAction(unit, this->extractorP->get(unit, allies, oponents)));
	case 'E':
		p = 1000 * (2 * unit.getPosition()) - this->extractorP->get(unit, allies, oponents);
		Terrain::clampPointInTerrain(p);
		return std::unique_ptr<Action>(new MoveAction(unit, p));
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

std::string Leaf::generateRandomCode()
{
	int action = rand() % 4;
	switch (action)
	{
	case 0:
		return std::string("!M") + ExtractorConstructor::generateRandomExtractorCode(0, ExtractorType::POINT_E);
	case 1:
		return std::string("!E") + ExtractorConstructor::generateRandomExtractorCode(0, ExtractorType::POINT_E);
	case 2:
		return std::string("!A") + ExtractorConstructor::generateRandomExtractorCode(0, ExtractorType::UNIT);
	default:
		return std::string("!N");
	}
}