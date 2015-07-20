#pragma once
#include "Army.hpp"
#include "AI.hpp"

class BattleParameter
{
public:
    Army myA;
    Army myB;
    int scoreA;
    int scoreB;
    bool log;
    AI ai;
    int turn;
    BattleParameter(Army A, Army B, int scoreA, int scoreB, bool log, AI ai, int turn) :
        myA(A), myB(B), scoreA(scoreA), scoreB(scoreB), log(log), ai(ai), turn(turn){}
    ~BattleParameter(){}
};

