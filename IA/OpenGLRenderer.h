#pragma once
#include "virtualOpenGL.h"
#include "Terrain.hpp"

#include <vector>

class OpenGLRenderer
{
public:
	OpenGLRenderer(int argc, char* argv[]);
	void Render();
	void AddElementToDraw(virtualOpenGl* element) { elementToDraw.push_back(element); }
	~OpenGLRenderer();
private:
	void Initialize();
	std::vector<virtualOpenGl*> elementToDraw;
};

