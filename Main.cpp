/*
            TECO'S ADVENTURES
TECNM/INSTITUTO TECNOLOGICO DE CIUDAD JUAREZ
SEMESTRE AGOSTO-DICIEMBRE 202
SOMNIAWORKS Todos los derechos reservados (C) 2024

Este programa esta sobre la licencia GPL-3.0

*/

#include <iostream>
#include <vector>
#include <GL/glut.h>
#include "Nivel1.h"
#include "GestorDeRecursos.h"
#include "Inicio.h"
#include "Mapa.h"

// Instancias globales
GestorRecursos gestorRecursos;
Inicio* pantallaInicio; // Instancia de la clase Inicio para alternar im�genes
Mapa* pantallaMapa; //Instancia de clase Mapa para mostrar avance de juego

// Variables Globales
int nivelActual = -1;
bool mostrarInicio = true; // Controla si solo se muestra una pantalla en blanco
/*
Para cuestiones de debug se propoen que nivelActual sea:
nivelActual = -1 --> Pantalla de Inicio
nivelActual = 0 --> Mapa del tec (seleccionar niveles)
nivelActual = 1 --> Nivel 1
nivelActual = 2 --> Nivel 2
nivelActual = 3 --> Nivel 3

**Niveles 2 y 3 estan en opcional, todavia no se sabe si
se realizaran
*/

void inicializacion();
void mostrar();
void finalizar();
void tecladoNoEspecial(unsigned char key, int x, int y);

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 640);
    glutCreateWindow("Teco's Adventures");

    inicializacion();
    glutIdleFunc(mostrar);
    glutDisplayFunc(mostrar);
    glutKeyboardFunc(tecladoNoEspecial);

    glutMainLoop();
    return 0;
}

void inicializacion() {
    // Configuraci�n inicial de OpenGL
    glClearColor(1.0, 1.0, 1.0, 1.0); // Fondo blanco inicial
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800.0, 0, 640.0);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Inicializar pantalla de inicio y cargar im�genes
    pantallaInicio = new Inicio(&gestorRecursos, 200); // Cambiar cada 500 ms
    pantallaInicio->cargarImagenes("inicio1", "Imagenes/Inicio/inicio1.png", "inicio2", "Imagenes/Inicio/inicio2.png");
}

void mostrar() {
    glClear(GL_COLOR_BUFFER_BIT); // Limpia la pantalla

    if (mostrarInicio) { // Mostrar pantalla de inicio
        pantallaInicio->alternarImagen();
        pantallaInicio->renderizar();
        glutSwapBuffers();
        return;
    }

    // Renderiza la pantalla seg�n el nivel actual
    switch (nivelActual) {
    case 0: // Mapa
        if (pantallaMapa) {
            pantallaMapa->renderizar();
        }
        else {
            std::cerr << "Error: pantallaMapa no est� inicializada." << std::endl;
        }
        break;
    case 1: // Nivel 1
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
    delete pantallaMapa;

    printf("Eso es todo viejo, hasta la proxima!\n");
    exit(0);
}

void tecladoNoEspecial(unsigned char key, int x, int y) {
    switch (key) {
    case 27: //ESC
        finalizar();
        break;
    case 13: //ENTER
        printf("Tecla ENTER presionada\n");
        if (nivelActual > 0) { // Todos los niveles
            printf("Se entro al IF, nivel actual: %d\n", nivelActual);
        }
        else { // Mapa o inicio
            if (nivelActual == -1) {//Si esta en inicio cambiar a mapa
                nivelActual = 0;
                mostrarInicio = false;
                if (!pantallaMapa) { // Crear pantallaMapa si no est� inicializado
                    pantallaMapa = new Mapa(&gestorRecursos);
                    pantallaMapa->init(); // Inicializar el mapa
                }
            }
            printf("Se entro al ELSE, nivel actual: %d\n", nivelActual);
        }
        break;
    case '1':
        nivelActual = 1;
        mostrarInicio = false; // Sal de la pantalla blanca
        printf("Tecla 1 presionada\n");
        initNivel1(); // Configura el nivel 1
        break;
    case 'm': // De men�
        printf("Tecla m presionada\n");
        nivelActual = -1;
        mostrarInicio = true; // Activa la pantalla blanca
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Fondo blanco
        break;
    default:
        break;
    }

    glutPostRedisplay(); // Solicita redibujar la pantalla
}
