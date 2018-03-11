#ifndef TYPES_H_
#define TYPES_H_

typedef struct _star{
	float projx;
	float projy;
	float z;

	struct _star *next;
} Star;

typedef struct {
	int width;
	int height;
	int depth;
	int range;

	int numStars;
	int starSize;
} SceneInfo;

typedef struct {
	int coordstep;
	int timestep;
} AnimationArgs;

Star *addStar(Star *head, Star *star);

#endif // TYPES_H_
