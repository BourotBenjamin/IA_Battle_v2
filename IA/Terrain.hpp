#pragma once
#include "Point.hpp"
#include "virtualOpenGL.h"
#include "CustomColor.h"

class Terrain : public virtualOpenGl
{
public:
	Terrain() {}
	~Terrain() {}
	void Initialize();
	static void clampPointInTerrain(Point& position);
	static int getMaxX() { return MAX_X; }
	static int getMaxY() { return MAX_Y; }
	static void setMaxX(int x) { MAX_X = x; }
	static void setMaxY(int y) { MAX_Y = y; }
	void draw(GLuint program);
private:
	static int MAX_X;
	static int MAX_Y;
	GLuint terrainVBO;
	GLuint terrainEBO;
    CustomColor myColor;
};