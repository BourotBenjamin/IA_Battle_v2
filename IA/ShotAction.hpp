#ifndef _SHOT_ACTION_HPP_
#define _SHOT_ACTION_HPP_
#include "Unit.hpp"
#include "Action.hpp"
#include <iomanip>
#include <iostream>
//
#include "OpenGLRenderer.h"

//Class representing the action of attacking one unit with another
class ShotAction : public Action {
private:
    Unit* unit_;
    Unit* opponent_;

public:
    //Constructor with as first paramter the unit attacking, and as second, its target
    ShotAction(Unit& unit, Unit& opponent):unit_(&unit), opponent_(&opponent) {}

    //Run the action
    //Log parameter indicate if we write something or not on the standard output
    void execute(bool log = false)
    {
        opponent_->takeDamage(unit_->getDamage().getValue());
        if (unit_->shoot())
        {
            unit_->missile = Missile(unit_->getPosition(), opponent_->getPosition());
            OpenGLRenderer::AddElementToDraw(&unit_->missile);
        }
        if(log) {
            float hp = opponent_->getLife().getValue();
            if(hp>0) {
                std::cout<<" ("<<hp<<"hp remaining)"<<std::endl;
            } else {
                //bug connu non r�solu de fa�on normal : 
                //si une unit� meurt alors qu'elle avait tir� ce tour ci le missile est d�truit et ne peux donc plus �tre draw
                OpenGLRenderer::RemoveElementToDraw(&opponent_->missile);
                OpenGLRenderer::RemoveElementToDraw(opponent_);
                std::cout<<" (dead !)"<<std::endl;
            }
        }
    }
};

#endif