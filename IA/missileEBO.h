
#pragma once

static const float g_missileVertices[] = {
    -0.33f, -0.33f, 0.33f,		// 0
    0.33f, -0.33f, 0.33f,  		// 1	
    0.33f, 0.33f, 0.33f,			// 2
    -0.33f, 0.33f, 0.33f,		// 3	
    -0.33f, -0.33f, -0.33f,		// 4
    0.1f, -0.1f, -0.33f,		// 5
    0.33f, 0.33f, -0.33f,		// 6
    -0.33f, 0.33f, -0.33f		// 7
};

static const unsigned short g_missileIndices[] = { 
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