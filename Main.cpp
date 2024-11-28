#include <iostream>
#include <vector>
#include <GL/glut.h>
#include "Nivel1.h"
#include "GestorDeRecursos.h"
#include "Inicio.h"

// Instancias globales
GestorRecursos gestorRecursos;
Inicio* pantallaInicio; // Instancia de la clase Inicio para alternar imágenes

int nivelActual = 0;
bool pantallaBlanca = true; // Controla si solo se muestra una pantalla en blanco

void inicializacion();
void mostrar();
void tecladoNoEspecial(unsigned char key, int x, int y);
void finalizar();

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Teco's Adventures");

    inicializacion();
    glutDisplayFunc(mostrar);
    glutKeyboardFunc(tecladoNoEspecial);

    glutMainLoop();
    return 0;
}

void inicializacion() {
    // Configuración inicial de OpenGL
    glClearColor(1.0, 1.0, 1.0, 1.0); // Fondo blanco inicial
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-400.0, 400.0, -300.0, 300.0);
    glEnable(GL_TEXTURE_2D);

    // Inicializar pantalla de inicio y cargar imágenes
    pantallaInicio = new Inicio(&gestorRecursos, 500); // Cambiar cada 500 ms
    pantallaInicio->cargarImagenes("inicio1", "Imagenes/Inicio/inicio1.png", "inicio2", "Imagenes/Inicio/inicio2.png");
}

void mostrar() {
    glClear(GL_COLOR_BUFFER_BIT); // Limpia la pantalla

    if (pantallaBlanca) {
        pantallaInicio->alternarImagen(); // Alterna la imagen según el tiempo transcurrido
        pantallaInicio->renderizar();     // Renderiza la imagen actual
        glutSwapBuffers();
        return;
    }

    // Renderiza el nivel actual si no está en modo pantalla blanca
    switch (nivelActual) {
    case 1:
        renderNivel1();
        break;
    default:
        break;
    }

    glutSwapBuffers(); // Intercambia buffers
}

void finalizar() {
    gestorRecursos.liberarRecursos(); // Libera los recursos del gestor
    delete pantallaInicio;            // Elimina la instancia de Inicio
}

void tecladoNoEspecial(unsigned char key, int x, int y) {
    switch (key) {
    case 27: //ESC
        finalizar();
        printf("Eso es todo viejo, hasta la próxima!\n");
        exit(0);
        break;
    case '1':
        nivelActual = 1;
        pantallaBlanca = false; // Sal de la pantalla blanca
        printf("Tecla 1 presionada\n");
        initNivel1(); // Configura el nivel 1
        break;
    case 'm':
        printf("Tecla m presionada\n");
        pantallaBlanca = true; // Activa la pantalla blanca
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Fondo blanco
        break;
    default:
        break;
    }

    glutPostRedisplay(); // Solicita redibujar la pantalla
}