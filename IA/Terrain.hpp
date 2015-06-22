#pragma once
#include "Point.hpp"
#include "OpenGLInclude.h"

class Terrain
{
public:
	static void Initialize(int Max_X, int Max_Y);
	static void clampPointInTerrain(Point& position);
	static int getMaxX() { return MAX_X; }
	static int getMaxY() { return MAX_Y; }
	static void setMaxX(int x) { MAX_X = x; }
	static void setMaxY(int y) { MAX_Y = y; }
	static void draw();
private:
	static int MAX_X;
	static int MAX_Y;
	static GLuint terrainVBO;
	static GLuint terrainEBO;
	static EsgiShader basicShader;
};