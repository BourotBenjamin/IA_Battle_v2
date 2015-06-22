#include "Terrain.hpp"

int Terrain::MAX_X;
int Terrain::MAX_Y;

GLuint Terrain::terrainVBO;
GLuint Terrain::terrainEBO;
EsgiShader Terrain::basicShader;

void Terrain::Initialize(int Max_X, int Max_Y)
{
	static const float g_Triangle[] = {
		-0.8f, 0.8f, 1.0f,
		0.0f, -0.8f, 0.5f,
		0.8f, 0.8f, 0.0f
	};

	basicShader.LoadVertexShader("basic.vs");
	basicShader.LoadFragmentShader("basic.fs");
	basicShader.Create();

	Terrain::setMaxX(Max_X);
	Terrain::setMaxY(Max_Y);

	glGenBuffers(1, &terrainVBO);
	glBindBuffer(GL_ARRAY_BUFFER, terrainVBO); // maintenant GL_ARRAY_BUFFER est triangleVBO
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)* 9, g_Triangle, GL_STATIC_DRAW); //en général
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	static const unsigned short inidicesTriangle[] = { 0, 1, 2 };
	glGenBuffers(1, &terrainEBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, terrainEBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned short)* 3, inidicesTriangle, GL_STATIC_DRAW);
}

void Terrain::clampPointInTerrain(Point& position) {

	if (position.getX() > Terrain::MAX_X)
	{
		position.setX(Terrain::MAX_X);
	}
	else if (position.getX() < 0)
	{
		position.setX(0);
	}
	if (position.getY() > Terrain::MAX_Y)
	{
		position.setY(Terrain::MAX_Y);
	}
	else if (position.getY() < 0)
	{
		position.setY(0);
	}
}

void Terrain::draw()
{
	GLuint program = basicShader.GetProgram();
	glUseProgram(basicShader.GetProgram());

	glBindBuffer(GL_ARRAY_BUFFER, terrainVBO);

	GLuint positionLocation = glGetAttribLocation(program, "a_position");
	glVertexAttribPointer(positionLocation, 2, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	glEnableVertexAttribArray(positionLocation);

	GLuint intensityLocation = glGetAttribLocation(program, "a_intensity");
	glVertexAttribPointer(intensityLocation, 1, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)(2 * sizeof(float)));
	glEnableVertexAttribArray(intensityLocation);

	GLint offsetLocation = glGetUniformLocation(program, "u_offset");
	glUniform3f(offsetLocation, 0.0f, 0.0f, 0.0f);

	GLint colorLocation = glGetUniformLocation(program, "u_constantColor");
	glUniform4f(colorLocation, 1.0f, 0.0f, 0.0f, 1.0f);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, terrainEBO);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, nullptr);
}