#pragma once
#include "Army.hpp"
#include "AI.hpp"

class BattleParameter
{
public:
    Army myA;
    Army myB;
    int& scoreA;
    int& scoreB;
    bool log;
    AI ai;
    int turn;
    void operator=(BattleParameter p)
    {
        this->myA = p.myA;
        this->myB = p.myB;
        this->scoreA = p.scoreA;
        this->scoreB = p.scoreB;
        this->log = p.log;
        this->ai = p.ai;
        this->turn = p.turn;
    }
    BattleParameter(Army& A, Army& B, int& scoreA, int& scoreB, bool log, AI ai, int turn) :
        myA(A), myB(B), scoreA(scoreA), scoreB(scoreB), log(log), ai(ai), turn(turn){}
    ~BattleParameter();
};

