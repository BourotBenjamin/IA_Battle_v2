#pragma once
#include "OpenGLInclude.h"

typedef void(*ButtonCallback)();

class CustomButton
{
public:
    CustomButton(int x, int y, int w, int h, int state, int highlighted, char* label, ButtonCallback callbackFunction) : x(x), y(y), w(w), h(h), state(state), highlighted(highlighted), label(label), callbackFunction(callbackFunction) {}
    void CustomButton::ButtonDraw();
    void CustomButton::ButtonPassive(int x, int y);
    int CustomButton::ButtonClickTest(int x, int y);
    ~CustomButton();
private:
    int   x, y, w, h;
    int	  state;						
    int	  highlighted;					
    char* label;						
    ButtonCallback callbackFunction;

    void CustomButton::Font(void *font, char *text, int x, int y);
};

