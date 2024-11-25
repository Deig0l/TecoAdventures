#include <Windows.h>
#include <iostream>
#include <GL/glut.h>
#include "Nivel1.h"
#include "Nivel2.h"
#include "Nivel3.h"

// Variable global para el nivel actual
int nivelActual = 1;

void onDisplay() {
    // Renderiza el nivel actual
    switch (nivelActual)
    {
    case 1:
        renderNivel1();
        break;
    case 2:
        renderNivel2();
        break;
    case 3:
        renderNivel3();
        break;
    default:
        break;
    }
}

void onUpdate(int value) {
    // Actualiza la lógica del nivel actual
    switch (nivelActual)
    {
    case 1:
        updateNivel1();
        break;
    case 2:
        updateNivel2();
        break;
    case 3:
        updateNivel3();
        break;
    default:
        break;
    }

    // Llama nuevamente a esta función después de 16ms (~60 FPS)
    glutTimerFunc(16, onUpdate, 0);
}

void onKeyboard(unsigned char key, int x, int y) {
    // Cambia de nivel con teclas

    switch (key)
    {
    case '1':
        nivelActual = 1;
        initNivel1();
        printf("Tecla 1 presionada\n");
        glutPostRedisplay();
        break;
    case '2':
        nivelActual = 2;
        initNivel2();
        printf("Tecla 2 presionada\n");
        glutPostRedisplay();
        break;
    case '3':
        nivelActual = 3;
        initNivel3();
        printf("Tecla 3 presionada\n");
        glutPostRedisplay();
        break;
    default:
        break;
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