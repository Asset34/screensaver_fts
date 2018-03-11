#include "types.h"

Star *addStar(Star *head, Star *star)
{
	star->next = head;
	
	return star;
}