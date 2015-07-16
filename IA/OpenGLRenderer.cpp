#include "OpenGLRenderer.h"

#include "battle.hpp"

Point lastPoint;
OpenGLRenderer* g_currentInstance;
std::vector<virtualOpenGl*> OpenGLRenderer::elementToDraw = std::vector<virtualOpenGl*>();
int previousTime = 0;

void _drawCallback()
{
	g_currentInstance->Render();
}

void _mouseCallback(int button, int state, int x, int y)
{
	g_currentInstance->MouseHandler(button,state,x,y);
}

void _motionCallback(int x, int y)
{
	g_currentInstance->MotionHandler( x,  y);
}

void _mouseWheelCallback(int button, int dir, int x, int y)
{
	g_currentInstance->MouseWheelHandler(button, dir, x, y);
}

void _keypressCallback(unsigned char key, int x, int y)
{
	g_currentInstance->KeyBoardHandler(key, x, y);
}

void _idleCallback(){
	g_currentInstance->IdleHandler();
}

OpenGLRenderer::OpenGLRenderer(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("IA Battle");

#ifdef FREEGLUT
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,
		GLUT_ACTION_GLUTMAINLOOP_RETURNS);
#endif

	this->Initialize();

	g_currentInstance = this;
	//
	glutMouseWheelFunc(_mouseWheelCallback);
	glutMouseFunc(_mouseCallback);
	glutMotionFunc(_motionCallback);
	glutDisplayFunc(_drawCallback);
	glutKeyboardFunc(_keypressCallback);
}

void OpenGLRenderer::StartDisplay(BattleParameter* parameter)//, std::function<void(BattleParameter*)> stepFunction)
{
    std::cout << "coucou" << std::endl;
    g_currentInstance->instanceParameter = parameter;
    //this->StepFunction = stepFunction;
    glutIdleFunc(_idleCallback);
	glutMainLoop();
}

void OpenGLRenderer::Initialize()
{
	GLenum error = glewInit();
	if (error != GL_NO_ERROR) {
		// TODO
	}

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	basicShader.LoadVertexShader("basic.vs");
	basicShader.LoadFragmentShader("basic.fs");
	basicShader.Create();

	Terrain* terrain = new Terrain();
	terrain->Initialize();

	depth = std::fmax(Terrain::getMaxX(), Terrain::getMaxY()) * -2 - 7.0f;
	previousTime = glutGet(GLUT_ELAPSED_TIME);

	this->AddElementToDraw(terrain);
}

void OpenGLRenderer::Render()
{
	glViewport(0, 0, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
	glClearColor(0.f, 0.f, 0.0f, 1.0f);
	glClearDepth(1.F);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	GLuint program = basicShader.GetProgram();
	glUseProgram(program);

	float w = (float)glutGet(GLUT_WINDOW_WIDTH);
	float h = (float)glutGet(GLUT_WINDOW_HEIGHT);

	int currentTime = glutGet(GLUT_ELAPSED_TIME);
	int delta = currentTime - previousTime;
	previousTime = currentTime;
	static float time = 1.f;
	time += delta / 1000.f;
	GLint timeLocation = glGetUniformLocation(program, "u_time");
	glUniform1f(timeLocation, time);

	float projection[16];
	OpenGLHelper::Perspective(projection, 45.f, w, h, 0.1f, 1000.f);
	GLint projLocation = glGetUniformLocation(program, "u_projectionMatrix");
	glUniformMatrix4fv(projLocation, 1, GL_FALSE, projection);

	float viewTransform[16];
	OpenGLHelper::Identity(viewTransform);
	viewTransform[14] = depth;
	GLint viewLocation = glGetUniformLocation(program, "u_viewMatrix");
	glUniformMatrix4fv(viewLocation, 1, GL_FALSE, viewTransform);

	float worldTransform[16];
	OpenGLHelper::Identity(worldTransform);
	float worldTransform2[16];
	OpenGLHelper::Rotate(worldTransform2, worldTransform, _angleY, .0f, .0f, 1.0f);
	GLint worldLocation = glGetUniformLocation(program, "u_worldMatrix");
	glUniformMatrix4fv(worldLocation, 1, GL_FALSE, worldTransform2);

	for (auto element : this->elementToDraw)
	{
		element->draw(program);
	}

	glUseProgram(0);

	glutSwapBuffers();
}

void OpenGLRenderer::MouseHandler(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		lastPoint.setX(x);
		lastPoint.setY(y);
		if (state == GLUT_DOWN)
			dragAction = true;
		else
			dragAction = false;
	}
}

void OpenGLRenderer::MotionHandler(int x, int y)
{
	if (dragAction)
	{
		double distanceX = x - lastPoint.getX();
		_angleY += 0.1*distanceX;
	}
	lastPoint.setX(x);
	lastPoint.setY(y);
	glutPostRedisplay();
}

void OpenGLRenderer::KeyBoardHandler(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'p' : //play pause
		this->isPaused = !isPaused;
		break;
	case 'n' : //mode pas a pas
		this->isStepByStep = !isStepByStep;
		break;
	case 'm' : //pas suivant
		this->isPaused = false;
		break;
	}
}

void OpenGLRenderer::IdleHandler()
{
	if (isPaused)
		return;
	std::cout << "execute step" << std::endl;
    executeOneTurn(g_currentInstance->instanceParameter);
    //g_currentInstance->instanceParameter->turn++;
	//this->StepFunction(this->instanceParameter);
	if (isStepByStep)
		isPaused = true;
}

void OpenGLRenderer::MouseWheelHandler(int button, int dir, int x, int y)
{
	depth += dir;
	glutPostRedisplay();
}

OpenGLRenderer::~OpenGLRenderer()
{
}
