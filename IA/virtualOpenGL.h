#pragma once
#include "OpenGLInclude.h"

class virtualOpenGl
{
public:
    State AnimationState = State::Default;
    bool isAnimating = false;
    bool canBeDestroy = false;
    bool BlockAnimation = false;
	virtual void draw(GLuint program) = 0;
    bool MustBeDestroy() { return canBeDestroy; }
};