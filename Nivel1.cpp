#include "Nivel1.h"
#include <iostream>
#include <GL/glut.h>
#include <ctime>

//Constructor
Nivel1::Nivel1(GestorRecursos* gestor)
    : gestorRecursos(gestor), indiceActual(0) {}

void Nivel1::initNivel1() {
    //// Inicializa elementos específicos del nivel 1
    //glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // Fondo azul

    if (imagenes.empty()) {//cargar la imagen y ponerla en el arreglo.
        cargarImagenes("FondoNivel1", "Imagenes/Niveles/BGN1.png");
    }
    imagenes.push_back("FondoNivel1");
}

void Nivel1::renderizarNivel1() {
    //glClear(GL_COLOR_BUFFER_BIT); // Limpia el buffer
    //glDisable(GL_TEXTURE_2D);
    //// Renderiza un cuadrado escalado y centrado
    //glPushMatrix();
    //glBegin(GL_QUADS);
    //glColor3f(0.0f, 1.0f, 0.0f);    // Color verde
    ////x400 y320
    //glVertex2f(300,220);//II
    //glVertex2f(500,220);//ID
    //glVertex2f(500,420);//SD
    //glVertex2f(300,420);//SI
    //glEnd();
    //glPopMatrix();
    //glEnable(GL_TEXTURE_2D);

    // Limpia la pantalla con el color de fondo
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Fondo negro

    // Establece el color blanco para evitar modificar la textura
    glColor3f(1.0f, 1.0f, 1.0f);

    GLuint texturaActual = gestorRecursos->obtenerTextura(imagenes[indiceActual]);
    if (texturaActual) {
        glBindTexture(GL_TEXTURE_2D, texturaActual);

        // Dibujar un cuadrado con la textura actual
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 0.0f, 0.0f); // Esquina inferior izquierda
        glTexCoord2f(1.0f, 1.0f); glVertex3f(800.0f, 0.0f, 0.0f);  // Esquina inferior derecha
        glTexCoord2f(1.0f, 0.0f); glVertex3f(800.0f, 640.0f, 0.0f);   // Esquina superior derecha
        glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 640.0f, 0.0f);  // Esquina superior izquierda
        glEnd();
    }
    else {
        std::cerr << "Error: No se pudo obtener la textura actual para renderizar." << std::endl;
    }

    //crearNivel(1);
}

void Nivel1::cargarImagenes(const std::string& nombre1, const std::string& ruta1) {
    gestorRecursos->cargarTextura(nombre1, ruta1.c_str());
    imagenes.push_back(nombre1);
}

//void updateNivel1() {
//    // Actualiza el estado del nivel si es necesario
//}
