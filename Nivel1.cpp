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
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);    // Color verde
    //x400 y320
    glVertex2f(300,220);//II
    glVertex2f(500,220);//ID
    glVertex2f(500,420);//SD
    glVertex2f(300,420);//SI
    glEnd();
    
    glPopMatrix();
}

void updateNivel1() {
    // Actualiza el estado del nivel si es necesario
}
