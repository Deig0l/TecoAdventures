#include <GL/glut.h>
#include "Nivel1.h"

void initNivel1() {
    // Inicializa elementos específicos del nivel 1
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // Fondo azul
}

void renderNivel1() {
    glClear(GL_COLOR_BUFFER_BIT); // Limpia el buffer

    // Renderiza un cuadrado escalado y centrado
    glPushMatrix();
    glScalef(100.0f, 100.0f, 1.0f); // Escalar el cuadrado para que sea visible
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);    // Color verde
    glVertex3f(-0.5f, -0.5f, 0.0f);
    glVertex3f(0.5f, -0.5f, 0.0f);
    glVertex3f(0.5f, 0.5f, 0.0f);
    glVertex3f(-0.5f, 0.5f, 0.0f);
    glEnd();
    glPopMatrix();
}

void updateNivel1() {
    // Actualiza el estado del nivel si es necesario
}
