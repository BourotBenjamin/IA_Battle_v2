#pragma once
#include "virtualOpenGL.h"
#include "Terrain.hpp"
#include "Point.hpp"

#include <vector>

class battleParameter
{
	Army myA;
	Army myB;
	int& scoreA;
	int& scoreB;
	bool log;
	AI ai;
	int turn;
	battleParameter(Army A, Army B, int& scoreA, int& scoreB, bool log, AI ai, int turn) :
		myA(A), myB(B), scoreA(scoreA), scoreB(scoreB), log(log), ai(ai), turn(turn){}
};

class OpenGLRenderer
{
public:
	OpenGLRenderer(int argc, char* argv[]);
	void Render();
	void MouseHandler(int button, int state, int x, int y);
	void MotionHandler(int x, int y);
	void KeyBoardHandler(unsigned char key, int x, int y);
	void MouseWheelHandler(int button, int dir, int x, int y);
	void IdleHandler();
	void StartDisplay(battleParameter &parameter);
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
	bool isPaused;
	bool isStepByStep;
	battleParameter &instanceParameter;
};

