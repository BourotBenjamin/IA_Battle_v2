
#pragma once

static const float g_cubeVertices[] = {
    // front
    -1.0f, -1.0f, 1.0f,
    1.0f, -1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f,
    // back
    -1.0f, -1.0f, -1.0f,
    1.0f, -1.0f, -1.0f,
    1.0f, 1.0f, -1.0f,
    -1.0f, 1.0f, -1.0f,
};

static const float g_littleCubeVertices[] = {
    // front
    -0.33f, -0.33f, 0.33f,
    0.33f, -0.33f, 0.33f,
    0.33f, 0.33f, 0.33f,
    -0.33f, 0.33f, 0.33f,
    // back
    -0.33f, -0.33f, -0.33f,
    0.33f, -0.33f, -0.33f,
    0.33f, 0.33f, -0.33f,
    -0.33f, 0.33f, -0.33f,
};

static const unsigned short g_cubeIndices[] = {
    // front
    0, 1, 2,
    2, 3, 0,
    // top
    3, 2, 6,
    6, 7, 3,
    // back
    7, 6, 5,
    5, 4, 7,
    // bottom
    4, 5, 1,
    1, 0, 4,
    // left
    4, 0, 3,
    3, 7, 4,
    // right
    1, 5, 6,
    6, 2, 1,
};

/*static const float g_cubeVertices[] = {
	-1.f, -1.f, 1.0f,		// 0
	1.f, -1.f, 1.0f,  		// 1	
	1.f, 1.f, 1.0f,			// 2
	-1.f, 1.f, 1.0f,		// 3	
	-1.f, -1.f, -1.0f,		// 4
	1.f, -1.f, -1.0f,		// 5
	1.f, 1.f, -1.0f,		// 6
	-1.f, 1.f, -1.0f		// 7
};

static const unsigned short g_cubeIndices[] = { 
	0, 1, 2, // avant
	2, 3, 0,
	3, 2, 6, // haut
	6, 7, 3,
	7, 6, 5, // arriere
	5, 4, 7,
	1, 5, 6, // droite
	6, 2, 1,		
	4, 0, 3, // gauche
	3, 7, 4,
	4, 5, 1, // bas
	1, 0, 4
};

/*static const float g_cubeVertices[] = {
    -1.0f, 1.0f, -1.0f,
    -1.0f, -1.0f, -1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f, -1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f, -1.0f, 1.0f,
    1.0f, 1.0f, -1.0f,
    1.0f, -1.0f, -1.0f
};

static const unsigned short g_cubeIndices[] = {
    0, 1, 2, 2, 1, 3,
    4, 5, 6, 6, 5, 7,
    3, 1, 5, 5, 1, 7,
    0, 2, 6, 6, 2, 4,
    6, 7, 0, 0, 7, 1,
    2, 3, 4, 4, 3, 5
};*/