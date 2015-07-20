#include "OpenGLRenderer.h"

#include "battle.hpp"

Point lastPoint;
OpenGLRenderer* g_currentInstance;
std::vector<virtualOpenGl*> OpenGLRenderer::elementToDraw = std::vector<virtualOpenGl*>();
int previousTime = 0;

void switchPauseButton() { g_currentInstance->isPaused = !g_currentInstance->isPaused; }

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

void OpenGLRenderer::StartDisplay(BattleParameter* parameter)
{
    //g_currentInstance->elementToDraw.clear();
    g_currentInstance->instanceParameter = parameter;
    g_currentInstance->instanceParameter->myA.AddDrawableUnit();
    g_currentInstance->instanceParameter->myB.AddDrawableUnit();
    glutIdleFunc(_idleCallback);
	glutMainLoop();
}

void OpenGLRenderer::Initialize()
{
    this->elementToDraw.clear();

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
	OpenGLHelper::Rotate(worldTransform2, worldTransform, _angleY, .0f, 1.0f, 0.0f);
    float worldTransform3[16];
    OpenGLHelper::Rotate(worldTransform3, worldTransform2, _angleX, 1.0f, .0f, .0f);
	GLint worldLocation = glGetUniformLocation(program, "u_worldMatrix");
	glUniformMatrix4fv(worldLocation, 1, GL_FALSE, worldTransform3);

    mustRedisplay=false;

    std::vector<virtualOpenGl*> listAttack = GetAnimatedElementForState(State::Attack);
    std::vector<virtualOpenGl*> listMove = GetAnimatedElementForState(State::Move);
    if (listAttack.size() < 1)
    {
        for (auto element : listMove)
            element->BlockAnimation = false;
    }
    else{
        for (auto element : listMove)
            element->BlockAnimation = true;
    }

    std::vector<virtualOpenGl*> destroyElement;

    for (auto element : this->elementToDraw)
	{
		element->draw(program);
        if (!mustRedisplay && element->isAnimating)
            mustRedisplay = true;
        if (element->MustBeDestroy())
        {
            destroyElement.push_back(element);
        }
	}

    for (auto element : destroyElement)
    {
        this->RemoveElementToDraw(element);
    }

	glUseProgram(0);

	glutSwapBuffers();

    if (mustRedisplay)
        glutPostRedisplay();
}

std::vector<virtualOpenGl*> OpenGLRenderer::GetAnimatedElementForState(State selectedState)
{
    std::vector<virtualOpenGl*> tmp;
    for (auto element : this->elementToDraw)
    {
        if (element->AnimationState == selectedState && element->isAnimating)
            tmp.push_back(element);
    }
    return tmp;
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
		_angleY += 0.2*distanceX;
        double distanceY = y - lastPoint.getY();
        _angleX += 0.2*distanceY;
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
    if (isPaused || mustRedisplay)
        return;
    executeOneTurn(g_currentInstance->instanceParameter);
    glutPostRedisplay();
	if (isStepByStep)
		isPaused = true;
}

void OpenGLRenderer::MouseWheelHandler(int button, int dir, int x, int y)
{
	depth += dir;
	glutPostRedisplay();
}

void OpenGLRenderer::RemoveElementToDraw(virtualOpenGl* element) 
{
    bool doDelete=false;
    int index;
    for (index = 0; index < elementToDraw.size(); index++)
    {
        if (elementToDraw.at(index) == element)
        {
            doDelete = true;
            break;
        }
    }
    if (doDelete)
        elementToDraw.erase(elementToDraw.begin() + index);
}

OpenGLRenderer::~OpenGLRenderer()
{
}
