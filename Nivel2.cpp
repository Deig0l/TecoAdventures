#include <GL/glut.h>
#include "Nivel2.h"

void initNivel2() {
    // Inicializa elementos específicos del nivel 2
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Fondo negro
}

void renderNivel2() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Renderiza los objetos del nivel 2
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, 0.0f);
    glVertex3f(0.5f, -0.5f, 0.0f);
    glVertex3f(0.0f, 0.5f, 0.0f);
    glEnd();
    glutSwapBuffers();
}

void updateNivel2() {

}