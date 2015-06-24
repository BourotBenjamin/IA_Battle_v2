#ifndef _BATTLE_HPP_
#define _BATTLE_HPP_
#include "Army.hpp"
#include "AI.hpp"
#include "OpenGLInclude.h"
#include "OpenGLRenderer.h"

//Run a fight between the two given armies, and store their score in the given variable.
void fight(const Army& a, const Army& b, int& scoreA, int& scoreB,OpenGLRenderer renderer, bool log = true);
void executeOneTurn(battleParameter &parameter);
void endBattle(battleParameter &parameter);
#endif