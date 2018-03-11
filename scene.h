#ifndef SCENE_H_
#define SCENE_H_

#include <stdlib.h>
#include <math.h>
#include <glut.h>

#include "types.h"
#include "geometry.h"

void InitializeScene(SceneInfo *sceneInfo);
void InitializeAnimation(AnimationArgs *animationArgs);

Star *generateStar(void);
Star *generateScene(void);
void updateStar(Star *star);

void moveStar(Star *star);
void moveScene(void);

void drawStar(Star *star);
void drawScene(void);
void clearScene(void);

void nextScene(int value);

#endif // SCENE_H_