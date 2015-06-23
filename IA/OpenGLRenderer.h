#pragma once
#include "virtualOpenGL.h"
#include "Terrain.hpp"
#include "Point.hpp"

#include <vector>

class OpenGLRenderer
{
public:
	OpenGLRenderer(int argc, char* argv[]);
	void Render();
	void MouseHandler(int button, int state, int x, int y);
	void MotionHandler(int x, int y);
	void MouseWheelHanlder(int button, int dir, int x, int y);
	void AddElementToDraw(virtualOpenGl* element) { elementToDraw.push_back(element); }
	~OpenGLRenderer();
private:
	void Initialize();
	std::vector<virtualOpenGl*> elementToDraw;
	GLuint terrainVBO;
	GLuint terrainEBO;
	EsgiShader basicShader;
	GLdouble _angleY;
	GLdouble _angleX;
	float depth = -7.0f;
	bool dragAction;
};

