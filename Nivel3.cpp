#include <GL/glut.h>
#include "Nivel1.h"

void initNivel3() {
    // Inicializa elementos específicos del nivel 3
    glClearColor(1.0f, 0.0f, 1.0f, 1.0f); // Fondo negro
}

void renderNivel3() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Renderiza los objetos del nivel 3
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3f(-0.5f, -0.5f, 0.0f);
    glVertex3f(1.5f, -0.5f, 0.0f);
    glVertex3f(1.5f, 0.5f, 0.0f);
    glVertex3f(-0.5f, 0.5f, 0.0f);
    glEnd();
    glutSwapBuffers();
}

void updateNivel3() {

}