#ifndef _BATTLE_HPP_
#define _BATTLE_HPP_
#include "Army.hpp"
#include "AI.hpp"
#include "OpenGLInclude.h"
#include "OpenGLRenderer.h"
#include "BattleParameter.h"

//Run a fight between the two given armies, and store their score in the given variable.
void fight(const Army& a, const Army& b, int& scoreA, int& scoreB, bool log = true);

void executeOneTurn(BattleParameter* parameter);
void endBattle(BattleParameter* parameter);

#endif