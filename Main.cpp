#include <iostream>
#include <vector>
#include <GL/glut.h>
#include "Nivel1.h"
#include "GestorDeRecursos.h"
#include "Inicio.h"
#include "Mapa.h"

// Instancias globales
GestorRecursos gestorRecursos;
Inicio* pantallaInicio; // Instancia de la clase Inicio para alternar imágenes
Mapa* pantallaMapa; //Instancia de clase Mapa para mostrar avance de juego

int nivelActual = -1;
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
bool mostrarInicio = true; // Controla si solo se muestra una pantalla en blanco

void inicializacion();
void mostrar();
void finalizar();
void tecladoNoEspecial(unsigned char key, int x, int y);
void ComprobacionInicioMapa();

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Teco's Adventures");

    inicializacion();
    glutIdleFunc(mostrar);
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
    gluOrtho2D(0, 800.0, 0, 600.0);
    glEnable(GL_TEXTURE_2D);

    // Inicializar pantalla de inicio y cargar imágenes
    pantallaInicio = new Inicio(&gestorRecursos, 200); // Cambiar cada 500 ms
    pantallaInicio->cargarImagenes("inicio1", "Imagenes/Inicio/inicio1.png", "inicio2", "Imagenes/Inicio/inicio2.png");
}

void mostrar() {
    glClear(GL_COLOR_BUFFER_BIT); // Limpia la pantalla

    if (mostrarInicio) {
        pantallaInicio->alternarImagen(); // Alterna la imagen según el tiempo transcurrido
        pantallaInicio->renderizar();     // Renderiza la imagen actual
        glutSwapBuffers();
        return;
    }

    // Renderiza el nivel actual si no está en modo pantalla blanca
    switch (nivelActual) {
    case 0:
        pantallaMapa->renderizar();
        break;
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
    delete pantallaMapa;
}

void tecladoNoEspecial(unsigned char key, int x, int y) {
    switch (key) {
    case 27: //ESC
        finalizar();
        printf("Eso es todo viejo, hasta la próxima!\n");
        exit(0);
        break;
    case 13: //ENTER
        printf("Tecla ENTER presionada\n");
        if (nivelActual > 0) { //todos los niveles
            printf("Se entro al IF, nivel actual: %d\n", nivelActual);
        }
        else // mapa o inicio
        {
            nivelActual = (nivelActual == -1) ? 0 : 0;
            printf("Se entro al ELSE, nivel actual: %d\n", nivelActual);
            ComprobacionInicioMapa();
        }
        break;
    case '1':
        nivelActual = 1;
        mostrarInicio = false; // Sal de la pantalla blanca
        printf("Tecla 1 presionada\n");
        initNivel1(); // Configura el nivel 1
        break;
    case 'm': //De menu
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

void ComprobacionInicioMapa() {
    switch (nivelActual) {
    case -1: //Inicio

        break;
    case 0: //Mapa
        //cargamos imagenes y renderizamos
        pantallaMapa = new Mapa(&gestorRecursos);
        pantallaMapa->cargarImagenes(
            "MapaNivel1", "Imagenes/Mapa/TecMapN1.png",
            "MapaNivel2", "Imagenes/Mapa/TecMapN2.png",
            "MapaNivel3", "Imagenes/Mapa/TecMapN3.png");
        break;
    default:
        break;
    }
    glutPostRedisplay();
}