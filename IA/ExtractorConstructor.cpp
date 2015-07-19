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

void* ExtractorConstructor::create(std::string* code)
{
	void* extractor = nullptr;
	char c = code->at(0);
	char c2 = code->at(1);
	char c3 = code->at(2);
	*code = std::string(std::string(code->begin() + 1, code->end()));
	switch (c)
	{
	case 'C':
		extractor = new ExtractorC(code);
		break;
	case 'D':
		extractor = new ExtractorD(code);
		break;
	case 'U':
		extractor = new ExtractorU();
		break;
	case 'B':
		extractor = new ExtractorB(code);
		break;
	case 'P':
		extractor = new ExtractorP(code);
		break;
	case 'A':
		extractor = new ExtractorA();
		break;
	case 'O':
		extractor = new ExtractorO();
		break;
	case 'M':
		*code = std::string(std::string(code->begin() + 2, code->end()));
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
		*code = std::string(std::string(code->begin() + 2, code->end()));
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
		*code = std::string(std::string(code->begin() + 2, code->end()));
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
	case 'L':
		*code = std::string(std::string(code->begin() + 2, code->end()));
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
		*code = std::string(std::string(code->begin() + 2, code->end()));
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
	case 'N':
		*code = std::string(std::string(code->begin() + 3, code->end()));
		switch (c2)
		{
		case 'L':
			switch (c3)
			{
			case 'D':
				extractor = new ExtractorNLD(code);
				break;
			default:
				extractor = new ExtractorNL(c3, code);
				break;
			}
		case 'H':
			switch (c3)
			{
			case 'D':
				extractor = new ExtractorNHD(code);
				break;
			default:
				extractor = new ExtractorNH(c3, code);
				break;
			}
		}
		break;
	case 'T':
		*code = std::string(std::string(code->begin() + 3, code->end()));
		switch (c2)
		{
		case 'L':
			switch (c3)
			{
			case 'D':
				extractor = new ExtractorTLD(code);
				break;
			default:
				extractor = new ExtractorTL(c3, code);
				break;
			}
		case 'H':
			switch (c3)
			{
			case 'D':
				extractor = new ExtractorTHD(code);
				break;
			default:
				extractor = new ExtractorTH(c3, code);
				break;
			}
		}
		break;
	}
	return extractor;
}
