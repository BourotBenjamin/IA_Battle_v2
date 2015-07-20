#include "CustomButton.h"

void CustomButton::ButtonDraw()
{
    int fontx;
    int fonty;

    if (this)
    {
        /*
        *	We will indicate that the mouse cursor is over the button by changing its
        *	colour.
        */
        if (this->highlighted)
            glColor3f(0.7f, 0.7f, 0.8f);
        else
            glColor3f(0.6f, 0.6f, 0.6f);

        /*
        *	draw background for the button.
        */
        glBegin(GL_QUADS);
        glVertex2i(this->x, this->y);
        glVertex2i(this->x, this->y + this->h);
        glVertex2i(this->x + this->w, this->y + this->h);
        glVertex2i(this->x + this->w, this->y);
        glEnd();

        /*
        *	Draw an outline around the button with width 3
        */
        glLineWidth(3);

        /*
        *	The colours for the outline are reversed when the button.
        */
        if (this->state)
            glColor3f(0.4f, 0.4f, 0.4f);
        else
            glColor3f(0.8f, 0.8f, 0.8f);

        glBegin(GL_LINE_STRIP);
        glVertex2i(this->x + this->w, this->y);
        glVertex2i(this->x, this->y);
        glVertex2i(this->x, this->y + this->h);
        glEnd();

        if (this->state)
            glColor3f(0.8f, 0.8f, 0.8f);
        else
            glColor3f(0.4f, 0.4f, 0.4f);

        glBegin(GL_LINE_STRIP);
        glVertex2i(this->x, this->y + this->h);
        glVertex2i(this->x + this->w, this->y + this->h);
        glVertex2i(this->x + this->w, this->y);
        glEnd();

        glLineWidth(1);


        /*
        *	Calculate the x and y coords for the text string in order to center it.
        */
        fontx = this->x + (this->w - glutBitmapLength(GLUT_BITMAP_HELVETICA_10, (unsigned char*)this->label)) / 2;
        fonty = this->y + (this->h + 10) / 2;

        /*
        *	if the button is pressed, make it look as though the string has been pushed
        *	down. It's just a visual thing to help with the overall look....
        */
        if (this->state) {
            fontx += 2;
            fonty += 2;
        }

        /*
        *	If the cursor is currently over the button we offset the text string and draw a shadow
        */
        if (this->highlighted)
        {
            glColor3f(0, 0, 0);
            Font(GLUT_BITMAP_HELVETICA_10, this->label, fontx, fonty);
            fontx--;
            fonty--;
        }

        glColor3f(1, 1, 1);
        Font(GLUT_BITMAP_HELVETICA_10, this->label, fontx, fonty);
    }
}

void CustomButton::ButtonPassive(int x, int y)
{
    if (this->ButtonClickTest( x, y))
    {
        if (this->highlighted == 0) {
            this->highlighted = 1;
            glutPostRedisplay();
        }
    }
    else
    {
        if (this->highlighted == 1)
        {
            this->highlighted = 0;
            glutPostRedisplay();
        }
    }
}

int CustomButton::ButtonClickTest(int x, int y)
{
    if (this)
    {
        /*
        *	If clicked within button area, then return true
        */
        if (x > this->x      &&
            x < this->x + this->w &&
            y > this->y      &&
            y < this->y + this->h) {
            return 1;
        }
    }

    /*
    *	otherwise false.
    */
    return 0;
}

void CustomButton::Font(void *font, char *text, int x, int y)
{
    glRasterPos2i(x, y);

    while (*text != '\0')
    {
        glutBitmapCharacter(font, *text);
        ++text;
    }
}

CustomButton::~CustomButton()
{
}
