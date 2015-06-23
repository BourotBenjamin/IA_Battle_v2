#include "Terrain.hpp"

int Terrain::MAX_X;
int Terrain::MAX_Y;

void Terrain::Initialize()
{
	static const float g_Triangle[] = {
		-MAX_X, -MAX_Y, 1.0f,		// 0
		MAX_X, -MAX_Y, 1.0f,  		// 1	
		 MAX_X,  MAX_Y, 1.0f,		// 2
		-MAX_X, MAX_Y, 1.0f		// 3
	};

	glGenBuffers(1, &terrainVBO);
	glBindBuffer(GL_ARRAY_BUFFER, terrainVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)* 3 * 4, g_Triangle, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	static const unsigned short indicesTriangle[] = {
		0, 1, 2,
		2, 3, 0
	};

	glGenBuffers(1, &terrainEBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, terrainEBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned short) * 3 * 2, indicesTriangle, GL_STATIC_DRAW);
}

void Terrain::clampPointInTerrain(Point& position) {

	if (position.getX() > Terrain::MAX_X)
	{
		position.setX(Terrain::MAX_X);
	}
	else if (position.getX() < -Terrain::MAX_X)
	{
		position.setX(-Terrain::MAX_X);
	}
	if (position.getY() > Terrain::MAX_Y)
	{
		position.setY(Terrain::MAX_Y);
	}
	else if (position.getY() < -Terrain::MAX_Y)
	{
		position.setY(-Terrain::MAX_Y);
	}
}

void Terrain::draw(GLuint program)
{
	glBindBuffer(GL_ARRAY_BUFFER, terrainVBO);

	GLint positionLocation = glGetAttribLocation(program, "a_position");
	glEnableVertexAttribArray(positionLocation);
	glVertexAttribPointer(positionLocation, 3, GL_FLOAT, GL_FALSE, sizeof(float)* 3, 0);

	glDrawArrays(GL_TRIANGLES, 0, 4);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, terrainEBO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, nullptr);
}