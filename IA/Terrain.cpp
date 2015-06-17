#include "Terrain.hpp"

int Terrain::MAX_X;
int Terrain::MAX_Y;

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