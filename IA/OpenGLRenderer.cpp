#include "OpenGLRenderer.h"


OpenGLRenderer* g_currentInstance;

void _drawCallback()
{
	g_currentInstance->Render();
}

OpenGLRenderer::OpenGLRenderer(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("IA Battle");

#ifdef FREEGLUT
	// Note: glutSetOption n'est disponible qu'avec freeGLUT
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,
		GLUT_ACTION_GLUTMAINLOOP_RETURNS);
#endif

	this->Initialize();

	g_currentInstance = this;
	glutDisplayFunc(_drawCallback);

	glutMainLoop();
}

void OpenGLRenderer::Initialize()
{
	GLenum error = glewInit();
	if (error != GL_NO_ERROR) {
		// TODO
	}
}

void OpenGLRenderer::Render()
{
	glViewport(0, 0, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
	glClearColor(0.f, 0.5f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	Terrain::draw();

	glutSwapBuffers();
	glutPostRedisplay();
}

OpenGLRenderer::~OpenGLRenderer()
{
}
