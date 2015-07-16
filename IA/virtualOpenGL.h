#pragma once
#include "OpenGLInclude.h"

class virtualOpenGl
{
public:
    State AnimationState = State::Default;
    bool isAnimating = false;
	virtual void draw(GLuint program) = 0;
};