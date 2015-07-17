#pragma once
#ifndef _MISSILE_HPP_
#define _MISSILE_HPP_
//#include "OpenGLRenderer.h"
#include "virtualOpenGL.h"

#include "CustomColor.h"
#include "Point.hpp"
#include "cube.h"

class Missile : public virtualOpenGl
{
public:
    Missile(){}
    Missile(Point startPos, Point endPos);
    void Missile::draw(GLuint program);
    ~Missile();
private:
    Point currentPosition;
    Point targetPosition;
    CustomColor color;
    GLuint missileEBO;
    GLuint missileVBO;
};
#endif