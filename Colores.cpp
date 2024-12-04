#include "Colores.h"

void asignarColor(ListaColores color) {
	switch (color) {
	case BLACK:
		glColor3f(0.0f, 0.0f, 0.0f);
		break;
	case WHITE:
		glColor3f(1.0f, 1.0f, 1.0f);
		break;
	case RED:
		glColor3f(1.0f, 0.0f, 0.0f);
		break;
	case GREEN:
		glColor3f(0.0f, 1.0f, 0.0f);
		break;
	case BLUE:
		glColor3f(0.0f, 0.0f, 1.0f);
		break;
	case LBLUE:
		glColor3f(0.23f, 0.35f, 0.41f);
		break;
	case YELLOW:
		glColor3f(1.0f, 1.0f, 0.0f);
		break;
	case MAGENTA:
		glColor3f(1.0f, 0.0f, 1.0f);
		break;
	case CYAN:
		glColor3f(0.0f, 1.0f, 1.0f);
		break;
	case GREY:
		glColor3f(0.5f, 0.5f, 0.5f);
		break;
	case LGREY:
		glColor3f(0.6f, 0.6f, 0.6f);
		break;
	case DGREY:
		glColor3f(0.2f, 0.2f, 0.2f);
		break;
	default:
		break;
	}
}
