#include "Missile.h"


Missile::Missile(Point startPos, Point endPos) : currentPosition(startPos), targetPosition(endPos)
{
    this->color = CustomColor(1.0f, 1.0f, 1.0f);
    this->AnimationState = State::Attack;
    this->isAnimating = true;

    glGenBuffers(1, &missileVBO);
    glBindBuffer(GL_ARRAY_BUFFER, missileVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_littleCubeVertices), g_littleCubeVertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glGenBuffers(1, &missileEBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, missileEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(g_cubeIndices), g_cubeIndices, GL_STATIC_DRAW);
}

void Missile::draw(GLuint program)
{
    glBindBuffer(GL_ARRAY_BUFFER, missileVBO);

    GLint positionLocation = glGetAttribLocation(program, "a_position");
    glEnableVertexAttribArray(positionLocation);
    glVertexAttribPointer(positionLocation, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);

    GLint colorLocation = glGetUniformLocation(program, "u_color");
    glUniform4f(colorLocation, this->color.RedValue, this->color.GreenValue, this->color.BlueValue, 1.0f);

    if (this->isAnimating && !this->BlockAnimation)
    {
        this->currentPosition.moveTo(this->targetPosition, 0.01f);
        if (currentPosition == targetPosition)
        {
            this->isAnimating = false;
            this->canBeDestroy = true;
        }
    }

    GLint offsetLocation = glGetUniformLocation(program, "u_offset");
    glUniform3f(offsetLocation, this->currentPosition.getX(), this->currentPosition.getY(), 0.0f);

    glDrawArrays(GL_TRIANGLES, 0, sizeof(g_cubeVertices));

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, missileEBO);
    glDrawElements(GL_TRIANGLES, sizeof(g_cubeIndices), GL_UNSIGNED_SHORT, nullptr);
}


Missile::~Missile()
{
}
