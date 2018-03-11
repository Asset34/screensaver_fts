#include "keys.h"

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case KEY_ESC:
		exit(0);
		break;
	case KEY_ENTER:
		glutFullScreen();
		break;
	}
}