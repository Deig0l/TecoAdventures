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
#include "GestorDeRecursos.h"
#include "Inicio.h"
#include "Mapa.h"
#include <Windows.h>
#include "Nivel.h"

// Instancias globales
GestorRecursos gestorRecursos;
Inicio* pantallaInicio; // Instancia de la clase Inicio para alternar imágenes
Mapa* pantallaMapa; //Instancia de clase Mapa para mostrar avance de juego

// Variables Globales
int nivelActual = -1;
int nivelesDesbloqueados = 1;
bool mostrarInicio = true; // Controla si solo se muestra una pantalla en blanco
bool audioReproduciendo = false;
/*
Para cuestiones de debug se proponen que nivelActual sea:
nivelActual = -1 --> Pantalla de Inicio
nivelActual = 0 --> Mapa del tec (seleccionar niveles)
nivelActual = 1 --> Nivel 1
nivelActual = 2 --> Nivel 2
nivelActual = 3 --> Nivel 3

*/

void inicializacion();
void mostrar();
void showInicio();
void showMapa();
void checkIfWin(int);
void tecladoNoEspecial(unsigned char key, int x, int y);
void finalizar();
void enterTecleado();
void reproducirAudio(int nivel);
void numTecleado(int nivel);
void emeTecleado();
void masTecleado();
void menosTecleado();

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 640);
	glutCreateWindow("Teco's Adventures");

	inicializacion();

	inicializarFlechas();

	//glutIdleFunc(mostrar);//permite que imagenes que alternan se muestren
	glutDisplayFunc(mostrar);
	glutKeyboardFunc(tecladoNoEspecial);
	glutSpecialFunc(controlesEspecial);

	glutMainLoop();
	return 0;
}

void inicializacion() {
	// Configuración inicial de OpenGL
	glClearColor(1.0, 1.0, 1.0, 1.0); // Fondo blanco inicial
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 800.0, 0, 640.0);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// Inicializar pantalla de inicio y cargar imágenes
	pantallaInicio = new Inicio(&gestorRecursos, 200); // Cambiar cada 500 ms
	pantallaInicio->cargarImagenes("inicio1", "Imagenes/Inicio/inicio1.png", "inicio2", "Imagenes/Inicio/inicio2.png");
	reproducirAudio(nivelActual);
}

void mostrar() {
	glClear(GL_COLOR_BUFFER_BIT); // Limpia la pantalla

	switch (nivelActual) {
	case -1: // Inicio
		showInicio();
		break;
	case 0: // Mapa
		showMapa();
		break;
	case 1: // Nivel 1
	case 2: // Nivel 2
	case 3: // Nivel 3
		mostrarNivel(); // Solo renderiza
		break;
	default:
		break;
	}

	glutSwapBuffers(); // Intercambia buffers
}

void showInicio() {
	if (mostrarInicio) { // Mostrar pantalla de inicio
		glutIdleFunc(mostrar);
		pantallaInicio->alternarImagen();
		pantallaInicio->renderizar();
	}
}

void showMapa() {
	if (pantallaMapa) {
		pantallaMapa->renderizarMapa();
	}
	else {
		std::cerr << "Error: pantallaMapa no está inicializada." << std::endl;
	}
}

void checkIfWin(int) {
	if (checkScore()) {
		printf_s("Felicidades");
	}
}

void tecladoNoEspecial(unsigned char key, int x, int y) {
	switch (key) {
	case 27: //ESC
		finalizar();
		break;
	case 13: //ENTER
		enterTecleado();
		break;
	case '1':
		numTecleado(1);
		//glutTimerFunc(0, secuenciaNivel1, 0);
		//glutTimerFunc(23000, checkIfWin, 0);
		break;
	case '2':
		numTecleado(2);
		//glutTimerFunc(0, secuenciaNivel2, 0);
		break;
	case '3':
		numTecleado(3);
		//glutTimerFunc(0, secuenciaNivel3, 0);
		break;
	case 'm': // De menú
		emeTecleado();
		break;
	case '+':
		masTecleado();
		break;
	case '-':
		menosTecleado();
		break;
	default:
		break;
	}

	glutPostRedisplay(); // Solicita redibujar la pantalla
}

void finalizar() {
	gestorRecursos.liberarRecursos(); // Libera los recursos del gestor
	delete pantallaInicio;            // Elimina la instancia de Inicio
	delete pantallaMapa;

	printf("Eso es todo viejo, hasta la proxima!\n");
	exit(0);
}

void enterTecleado() {
	printf("Tecla ENTER presionada\n");
	if (nivelActual == 0) { // Estamos en mapa
		printf("Estamos en Mapa: %d\n", nivelActual);
		printf("Se entro al IF, nivel actual: %d\n", nivelActual);
		switch (nivelesDesbloqueados) {
			case 1:
				numTecleado(1);
				break;
			case 2:
				numTecleado(2);
				break;
			case 3:
				numTecleado(3);
				break;
			default:
				break;
		}

	}
	else { // Estamos en inicio
		if (nivelActual == -1) {//Si esta en inicio cambiar a mapa
			nivelActual = 0;
			mostrarInicio = false;
			if (!pantallaMapa) { // Crear pantallaMapa si no está inicializado
				pantallaMapa = new Mapa(&gestorRecursos);
				pantallaMapa->initMapa(); // Inicializar el mapa
			}
		}
		printf("Se entro al ELSE, nivel actual: %d\n", nivelActual);
	}
}

void reproducirAudio(int nivel) {
	// Detener el audio actual si ya hay uno reproduciéndose
	if (audioReproduciendo) {
		PlaySound(NULL, NULL, 0); // Detiene cualquier sonido en reproducción
	}

	// Inicia el audio del nuevo nivel
	switch (nivel)
	{
	case -1:
		PlaySound(TEXT("Audio/AudioInit.wav"), NULL, SND_ASYNC | SND_LOOP);
		break;
	case 1:
		PlaySound(TEXT("Audio/AudioN1.wav"), NULL, SND_ASYNC | SND_LOOP);
		break;
	case 2:
		PlaySound(TEXT("Audio/AudioN2.wav"), NULL, SND_ASYNC | SND_LOOP);
		break;
	case 3:
		PlaySound(TEXT("Audio/AudioN3.wav"), NULL, SND_ASYNC | SND_LOOP);
		break;
	default:
		break;
	}

	// Actualiza el estado
	audioReproduciendo = true;
}

void numTecleado(int nivel) {
	if (nivelActual != nivel) {
		nivelActual = nivel;
		crearNivel(nivel); // Solo llama a `crearNivel` una vez aquí
	}
	reproducirAudio(nivel);
	mostrarInicio = false; // Sal de la pantalla blanca
	printf("Tecla %d presionada\n", nivel);
}

void emeTecleado() {
	printf("Tecla m presionada\n");
	nivelActual = -1;
	reproducirAudio(nivelActual);
	mostrarInicio = true; // Activa la pantalla blanca
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Fondo blanco
}

void masTecleado() {
	if (nivelActual == 0) {//si estamos en mapa
		pantallaMapa->siguienteIndice();//Nos movemos a la siguiente imagen
		nivelesDesbloqueados++;//Aumentamos la variable nivelesDesbloqueados
		if (nivelesDesbloqueados > 3) {//En caso de llegar a la ultima imagen
			nivelesDesbloqueados = 1;	//al presionar '+' regresamos a la img 1
		}
		printf("El nivel seleccionado es: %d\n", nivelesDesbloqueados);//comentario de consola debug
	}
}

void menosTecleado() {
	if (nivelActual == 0) {//si estamos en mapa
		pantallaMapa->indiceAnterior();//Nos movemos a la imagen anterior
		nivelesDesbloqueados--;//Decrementamos la variable nivelesDesbloqueados
		if (nivelesDesbloqueados < 1) {//Es caso de estar la img 1 y decrementar
			nivelesDesbloqueados = 3;//Nos movemos a la ultima imagen
		}
		printf("El nivel seleccionado es: %d\n", nivelesDesbloqueados);//Comentario de consola debug
	}
}
