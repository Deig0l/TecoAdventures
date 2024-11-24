#include <Windows.h>
#include <iostream>
#include <GL/glut.h>
#include "Nivel1.h"
#include "Nivel2.h"

// Variable global para el nivel actual
int nivelActual = 1;

void onDisplay() {
    // Renderiza el nivel actual
    if (nivelActual == 1) {
        renderNivel1();
    }
    else if (nivelActual == 2) {
        renderNivel2();
    }
}

void onUpdate(int value) {
    // Actualiza la lógica del nivel actual
    if (nivelActual == 1) {
        updateNivel1();
    }
    else if (nivelActual == 2) {
        updateNivel2();
    }

    // Llama nuevamente a esta función después de 16ms (~60 FPS)
    glutTimerFunc(16, onUpdate, 0);
}

void onKeyboard(unsigned char key, int x, int y) {
    // Cambia de nivel con teclas
    if (key == '1') {
        nivelActual = 1;
        initNivel1();
        printf("Presionando 1\n");
        glutPostRedisplay();
    }
    else if (key == '2') {
        nivelActual = 2;
        initNivel2();
        printf("Presionando 2\n");
        glutPostRedisplay();
    }
}

int main(int argc, char** argv) {
    // Inicializa GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Juego con Niveles");

    // Inicializa el primer nivel
    initNivel1();

    // Registra funciones de callback
    glutDisplayFunc(onDisplay);
    glutKeyboardFunc(onKeyboard);
    glutTimerFunc(16, onUpdate, 0); // Inicia el bucle de actualización

    // Inicia el bucle principal
    glutMainLoop();
    return 0;
}