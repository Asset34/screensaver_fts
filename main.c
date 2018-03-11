#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "scene.h"
#include "keys.h"

/* Settings */
#define WIDTH		 1280
#define HEIGHT		 720
#define DEPTH		 2000
#define PROJ_RANGE	 10
#define NUMBER_STARS 300
#define STAR_SIZE    3
#define COORD_STEP   10
#define TIME_STEP    10

int main(int argc, char **argv)
{
    // GLUT initialization
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Space");

	// Set proj
    gluOrtho2D(-WIDTH/2, WIDTH /2, -HEIGHT/2, HEIGHT /2);

	// Set scene parameters
	SceneInfo sinfo;
	sinfo.width = WIDTH;
	sinfo.height = HEIGHT;
	sinfo.depth = DEPTH;
	sinfo.numStars = NUMBER_STARS;
	sinfo.range = PROJ_RANGE;
	sinfo.starSize = STAR_SIZE;

	AnimationArgs aargs;
	aargs.coordstep = COORD_STEP;
	aargs.timestep = TIME_STEP;

	// Scene initialization
	InitializeScene(&sinfo);

	// Animation initialization
	InitializeAnimation(&aargs);

    // GLUT event handlers
    glutDisplayFunc(drawScene);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
}
