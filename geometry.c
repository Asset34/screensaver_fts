#include "geometry.h"

void computeXYProj(Star *star, int dz, int dist)
{
	float factor = 1 + dz / (dist + star->z);

	star->projx = star->projx * factor;
	star->projy = star->projy * factor;
}

float computeAlphaComponent(Star *star, int depth)
{
	return 1 - (star->z * star->z) / (depth * depth);
}