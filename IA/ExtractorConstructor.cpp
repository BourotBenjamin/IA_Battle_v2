#include "ExtractorConstructor.h"
#include "Extractor.h"
#include "Extractor_a.h"
#include "Extractor_aD.h"
#include "Extractor_m.h"
#include "Extractor_mD.h"
#include "ExtractorA.h"
#include "ExtractorB.h"
#include "ExtractorC.h"
#include "ExtractorD.h"
#include "ExtractorH.h"
#include "ExtractorHD.h"
#include "ExtractorL.h"
#include "ExtractorLD.h"
#include "ExtractorM.h"
#include "ExtractorMD.h"
#include "ExtractorNH.h"
#include "ExtractorNHD.h"
#include "ExtractorNL.h"
#include "ExtractorNLD.h"
#include "ExtractorO.h"
#include "ExtractorP.h"
#include "ExtractorTH.h"
#include "ExtractorTHD.h"
#include "ExtractorTL.h"
#include "ExtractorTLD.h"
#include "ExtractorU.h"


ExtractorConstructor::ExtractorConstructor()
{
}


ExtractorConstructor::~ExtractorConstructor()
{
}

std::unique_ptr<Extractor<Unit>> ExtractorConstructor::createUnitExtractor(std::string* code)
{
	Extractor<Unit>* extractor = nullptr;
	char c2, c3;
	char c = code->at(0);
	if (code->length() > 1)
		c2 = code->at(1);
	if (code->length() > 2)
		c3 = code->at(2);
	*code = std::string(std::string(code->begin() + 1, code->end()));
	switch (c)
	{
	case 'U':
		extractor = new ExtractorU();
		break;
	case 'L':
		*code = std::string(std::string(code->begin() + 1, code->end()));
		switch (c2)
		{
		case 'D':
			extractor = new ExtractorLD(code);
			break;
		default:
			extractor = new ExtractorL(c2, code);
			break;
		}
		break;
	case 'H':
		*code = std::string(std::string(code->begin() + 1, code->end()));
		switch (c2)
		{
		case 'D':
			extractor = new ExtractorHD(code);
			break;
		default:
			extractor = new ExtractorH(c2, code);
			break;
		}
		break;
	}
	return std::unique_ptr<Extractor<Unit>>(extractor);
}
std::unique_ptr<Extractor<Point>> ExtractorConstructor::createPointExtractor(std::string* code)
{
	Extractor<Point>* extractor = nullptr;
	char c2, c3;
	char c = code->at(0);
	if (code->length() > 1)
		c2 = code->at(1);
	if (code->length() > 2)
		c3 = code->at(2);
	*code = std::string(std::string(code->begin() + 1, code->end()));
	switch (c)
	{
	case 'B':
		extractor = new ExtractorB(code);
		break;
	case 'P':
		extractor = new ExtractorP(code);
		break;
	}
	return std::unique_ptr<Extractor<Point>>(extractor);
}
std::unique_ptr<Extractor<double>> ExtractorConstructor::createValueExtractor(std::string* code)
{
	Extractor<double>* extractor = nullptr;
	char c2, c3;
	char c = code->at(0);
	if (code->length() > 1)
		c2 = code->at(1);
	if (code->length() > 2)
		c3 = code->at(2);
	*code = std::string(std::string(code->begin() + 1, code->end()));
	switch (c)
	{
	case 'C':
		*code = std::string(std::string(code->begin() + 1, code->end()));
		extractor = new ExtractorC(c2, code);
		break;
	case 'D':
		extractor = new ExtractorD(code);
		break;
	case 'M':
		*code = std::string(std::string(code->begin() + 1, code->end()));
		switch (c2)
		{
		case 'D':
			extractor = new ExtractorMD(code);
			break;
		default:
			extractor = new ExtractorM(c2, code);
			break;
		}
		break;
	case 'm':
		*code = std::string(std::string(code->begin() + 1, code->end()));
		switch (c2)
		{
		case 'D':
			extractor = new Extractor_mD(code);
			break;
		default:
			extractor = new Extractor_m(c2, code);
			break;
		}
		break;
	case 'a':
		*code = std::string(std::string(code->begin() + 1, code->end()));
		switch (c2)
		{
		case 'D':
			extractor = new Extractor_aD(code);
			break;
		default:
			extractor = new Extractor_a(c2, code);
			break;
		}
		break;
	}
	return std::unique_ptr<Extractor<double>>(extractor);
}
std::unique_ptr<Extractor<UnitSet>> ExtractorConstructor::createArmyExtractor(std::string* code)
{
	Extractor<UnitSet>* extractor = nullptr;
	char c2, c3;
	char c = code->at(0);
	if (code->length() > 1)
		c2 = code->at(1);
	if (code->length() > 2)
		c3 = code->at(2);
	*code = std::string(std::string(code->begin() + 1, code->end()));
	switch (c)
	{
	case 'A':
		extractor = new ExtractorA();
		break;
	case 'O':
		extractor = new ExtractorO();
		break;
	case 'N':
		*code = std::string(std::string(code->begin() + 1, code->end()));
		switch (c2)
		{
		case 'L':
			switch (c3)
			{
			case 'D':
				*code = std::string(std::string(code->begin() + 1, code->end()));
				extractor = new ExtractorNLD(code);
				break;
			default:
				extractor = new ExtractorNL(c3, code);
				break;
			}
			break;
		case 'H':
			switch (c3)
			{
			case 'D':
				*code = std::string(std::string(code->begin() + 1, code->end()));
				extractor = new ExtractorNHD(code);
				break;
			default:
				extractor = new ExtractorNH(c3, code);
				break;
			}
			break;
		}
		break;
	case 'T':
		*code = std::string(std::string(code->begin() + 1, code->end()));
		switch (c2)
		{
		case 'L':
			switch (c3)
			{
			case 'D':
				*code = std::string(std::string(code->begin() + 1, code->end()));
				extractor = new ExtractorTLD(code);
				break;
			default:
				extractor = new ExtractorTL(c3, code);
				break;
			}
			break;
		case 'H':
			switch (c3)
			{
			case 'D':
				*code = std::string(std::string(code->begin() + 1, code->end()));
				extractor = new ExtractorTHD(code);
				break;
			default:
				extractor = new ExtractorTH(c3, code);
				break;
			}
			break;
		}
		break;
	}
	return std::unique_ptr<Extractor<UnitSet>>(extractor);
}

std::string ExtractorConstructor::generateRandomExtractorCode(int i, ExtractorType type)
{
	int r = 0;
	++i;
	switch (type)
	{
	case UNIT:
		if (i>5)
			return ExtractorU::generateRandomCode(i);
		r = rand() % 5;
		switch (r)
		{
		case 0:
			return ExtractorH::generateRandomCode(i);
			break;
		case 1:
			return ExtractorHD::generateRandomCode(i);
			break;
		case 2:
			return ExtractorL::generateRandomCode(i);
			break;
		case 3:
			return ExtractorLD::generateRandomCode(i);
			break;
		case 4:
			return ExtractorU::generateRandomCode(i);
			break;
		}
		break;
	case POINT_E:
		r = rand() % 2;
		switch (r)
		{
		case 0:
			return ExtractorB::generateRandomCode(i);
			break;
		case 1:
			return ExtractorP::generateRandomCode(i);
			break;
		}
		break;
	case VALUE:
		r = rand() % 8;
		switch (r)
		{
		case 0:
			return Extractor_a::generateRandomCode(i);
			break;
		case 1:
			return Extractor_aD::generateRandomCode(i);
			break;
		case 2:
			return Extractor_m::generateRandomCode(i);
			break;
		case 3:
			return Extractor_mD::generateRandomCode(i);
			break;
		case 4:
			return ExtractorC::generateRandomCode(i);
			break;
		case 5:
			return ExtractorD::generateRandomCode(i);
			break;
		case 6:
			return ExtractorM::generateRandomCode(i);
			break;
		case 7:
			return ExtractorMD::generateRandomCode(i);
			break;
		}
		break;
	case ARMY:
		if (i>5)
			r = rand() % 2;
		else
			r = rand() % 10;
		switch (r)
		{
		case 0:
			return ExtractorA::generateRandomCode(i);
			break;
		case 1:
			return ExtractorO::generateRandomCode(i);
			break;
		case 2:
			return ExtractorNHD::generateRandomCode(i);
			break;
		case 3:
			return ExtractorNL::generateRandomCode(i);
			break;
		case 4:
			return ExtractorNLD::generateRandomCode(i);
			break;
		case 5:
			return ExtractorNH::generateRandomCode(i);
			break;
		case 6:
			return ExtractorTH::generateRandomCode(i);
			break;
		case 7:
			return ExtractorTHD::generateRandomCode(i);
			break;
		case 8:
			return ExtractorTL::generateRandomCode(i);
			break;
		case 9:
			return ExtractorTLD::generateRandomCode(i);
			break;
		}
		break;
	}
	return std::string("");
}
