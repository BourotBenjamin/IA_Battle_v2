#pragma once
#include "OpenGLInclude.h"

class virtualOpenGl
{
public:
    bool isAnimating = false;
    float animationStartTime;
	virtual void draw(GLuint program) = 0;
};