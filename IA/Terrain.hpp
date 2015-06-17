#include "Point.hpp"

class Terrain
{
public:
	static void clampPointInTerrain(Point& position);
	static int getMaxX() { return MAX_X; }
	static int getMaxY() { return MAX_Y; }
	static void setMaxX(int x) { MAX_X = x; }
	static void setMaxY(int y) { MAX_Y = y; }
private:
	static int MAX_X;
	static int MAX_Y;
};