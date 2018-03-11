#include "scene.h"

/* Scene parameters */
static SceneInfo *sinfo = NULL;
static AnimationArgs *aargs = NULL;

/* Objects of the scene */
static Star *head = NULL;

void InitializeScene(SceneInfo *sceneInfo)
{
	sinfo = sceneInfo;
	head = generateScene();
}

void InitializeAnimation(AnimationArgs *animationArgs)
{
	aargs = animationArgs;
	nextScene(0);
}

Star *generateStar(void)
{
	Star *star = (Star*) malloc(sizeof(Star));

	star->projx = -sinfo->width / 2 + rand() % sinfo->width;
	star->projy = -sinfo->height / 2 + rand() % sinfo->height;
	star->z = sinfo->depth / 2 + rand() % (sinfo->depth / 2);

	return star;
}

void updateStar(Star *star)
{
	star->projx = -sinfo->width / 2 + rand() % sinfo->width;
	star->projy = -sinfo->height / 2 + rand() % sinfo->height;
	star->z = sinfo->depth;
}

Star *generateScene(void)
{
	Star *star = NULL;
	int i;
	for (i = 0; i < sinfo->numStars; i++) {
		star = generateStar();
		head = addStar(head, star);
	}

	return head;
}

void moveStar(Star *star)
{
	star->z -= aargs->coordstep;
	computeXYProj(star, aargs->coordstep, sinfo->range);
}

void moveScene(void)
{
	Star *star = head;
	while (star != NULL) {
		moveStar(star);

		if (fabsf(star->projx) > sinfo->width/2 ||
			fabsf(star->projy) > sinfo->height/2) {
			updateStar(star);
		}

		star = star->next;
	}
}

void drawStar(Star *star)
{
	// Set size of the star
	glPointSize(sinfo->starSize);

	// Set alpha component of the star
	float alpha = computeAlphaComponent(star, sinfo->depth);
	glColor4f(1, 1, 1, alpha);

	// Draw star	
	glBegin(GL_POINTS);
	glVertex2f(star->projx, star->projy);
	glEnd();
}

void drawScene(void)
{
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	Star *star = head;
	while (star != NULL) {
		drawStar(star);

		star = star->next;
	}

	glutSwapBuffers();
}

void clearScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void nextScene(int value)
{
	clearScene();

	moveScene();
	drawScene();

	glutTimerFunc(aargs->timestep, nextScene, value);
}