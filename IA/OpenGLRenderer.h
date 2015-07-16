#pragma once
#include "virtualOpenGL.h"
#include "Terrain.hpp"
#include "Point.hpp"

#include "Army.hpp"
#include "AI.hpp"
#include "BattleParameter.h"

#include <vector>
#include <functional>

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
    static void StartDisplay(BattleParameter* parameter);
    static void AddElementToDraw(virtualOpenGl* element) { elementToDraw.push_back(element); }
    static void RemoveElementToDraw(virtualOpenGl* element);
	~OpenGLRenderer();
private:
	void Initialize();
	static std::vector<virtualOpenGl*> elementToDraw;
	GLuint terrainVBO;
	GLuint terrainEBO;
	EsgiShader basicShader;
	GLdouble _angleY;
	GLdouble _angleX;
	float depth = -7.0f;
	bool dragAction;
	bool isPaused=false;
	bool isStepByStep=true;
	BattleParameter* instanceParameter;
    bool mustRedisplay;

    std::vector<virtualOpenGl*> OpenGLRenderer::GetAnimatedElementForState(State selectedState);
};

