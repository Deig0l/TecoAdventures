#include "Nivel.h"

std::vector<std::string> imagenes;
GestorRecursos gestor;
GestorRecursos* gestorRecursos = &gestor;

float LFx = 30;
float UPx = 130;
float DWx = 230;
float RTx = 330;

int numFlechas = 10;
float posicionOrigenY = -88.0;
float posicionMaxY = 640.0;
float velocidad = 0.2;

int score = 0;

float metaY = 500;

float t1 = 6;
float t2 = 20;
float t3 = 36;
float t4 = 56;
float t5 = 72;
float t6 = 87;

bool win = false;

float N1win = 140.0;

int topLF = 0;
int topUP = 0;
int topDW = 0;
int topRT = 0;

FlechaLEFT fLFSilueta(LFx, metaY, 8);
FlechaLEFT fLF0(LFx, posicionOrigenY, 8, YELLOW);

FlechaUP fUPSilueta(UPx, metaY, 8);
FlechaUP fUP0(UPx, posicionOrigenY, 8, BLUE);

FlechaDOWN fDWSilueta(DWx, metaY, 8);
FlechaDOWN fDW0(DWx, posicionOrigenY, 8, RED);

FlechaRIGHT fRTSilueta(RTx, metaY, 8);
FlechaRIGHT fRT0(RTx, posicionOrigenY, 8, GREEN);

FlechaLEFT fLFArray[10];
FlechaUP fUPArray[10];
FlechaDOWN fDWArray[10];
FlechaRIGHT fRTArray[10];

void inicializarFlechas() {
	for (int i = 0; i < numFlechas; ++i) {
		fLFArray[i] = FlechaLEFT(LFx, posicionOrigenY, 8, YELLOW);
		fUPArray[i] = FlechaUP(UPx, posicionOrigenY, 8, BLUE);
		fDWArray[i] = FlechaDOWN(DWx, posicionOrigenY, 8, RED);
		fRTArray[i] = FlechaRIGHT(RTx, posicionOrigenY, 8, GREEN);
	}
}

void crearNivel(int n) {
	//inicializarFlechas();
	//inicializacionNivel();
	//glutTimerFunc(0, secuenciaNivel1, 0);
	switch (n)
	{
	case 1:
		//velocidad = 0.1;
		velocidad = 0.1;
		/*glutTimerFunc(0, secuenciaNivel1, 0);*/
		//glutTimerFunc(21500, finishLevel, 0);
		break;
	case 2:
		velocidad = 0.2;
		//glutTimerFunc(0, secuenciaNivel2, 0);
		break;
	case 3:
		velocidad = 0.3;
		/*glutTimerFunc(0, secuenciaNivel3, 0);*/
		break;
	default:
		break;
	}
	cargarImagenes(
		"FondoN1", "Imagenes/Niveles/BGN1.png",
		"FondoN2", "Imagenes/Niveles/BGN2.png",
		"FondoN3", "Imagenes/Niveles/BGN3.png"
	);
	mostrarFondo(n);
	mostrarNivel();
	/*glutDisplayFunc(mostrarNivel);
	glutKeyboardFunc(controlesJuego);
	glutSpecialFunc(controlesEspecial);
	glutMainLoop();*/
}

void inicializacionNivel(void) {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(150, 50);
	glutInitWindowSize(800, posicionMaxY);
	glutCreateWindow("Prueba TecoAdventures");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 800.0, 0.0, posicionMaxY);
}

void writeBitmapString(void* font, const char* string) {
	const char* c;
	for (c = string; *c != '\0'; c++) {
		glutBitmapCharacter(font, *c);
	}
}

void mostrarNivel(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	escribirPuntuacion();

	// Siluetas grises
	fDWSilueta.dibujar();
	fUPSilueta.dibujar();
	fLFSilueta.dibujar();
	fRTSilueta.dibujar();

	dibujarFlechas();
	glFlush();
	glutPostRedisplay();
}

void mostrarFondo(int niveles) {
	// Verifica que las imágenes estén cargadas y el índice sea válido
	if (imagenes.empty()) {
		std::cerr << "Error: No se han cargado imágenes.\n";
		return;
	}

	if (niveles < 0 || niveles >= static_cast<int>(imagenes.size())) {
		std::cerr << "Error: índice fuera de rango al acceder a las imágenes. Niveles: "
			<< niveles << ", Tamaño del vector: " << imagenes.size() << "\n";
		return;
	}

	GLuint texturaActual = gestorRecursos->obtenerTextura(imagenes[niveles]);
	if (texturaActual) {
		glBindTexture(GL_TEXTURE_2D, texturaActual);

		glColor3f(1.0f, 1.0f, 1.0f); // Color blanco para no alterar la textura
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 0.0f, 0.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(800.0f, 0.0f, 0.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(800.0f, 640.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 640.0f, 0.0f);
		glEnd();
	}
	else {
		std::cerr << "Error: No se pudo obtener la textura actual.\n";
	}
}

void escribirPuntuacion() {
	glColor3f(1.0, 1.0, 1.0);
	glRasterPos2f(500.0, 550.0);
	string str_score = to_string(score);
	writeBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, ("SCORE: " + str_score).c_str());
}

void dibujarFlechas() {
	for (int i = 0; i < numFlechas; i++) {
		if (fLFArray[i].getMover()) {
			if (fLFArray[i].getY() < posicionMaxY) {
				fLFArray[i].incY(velocidad);
				fLFArray[i].dibujar();
			}
			else {
				if (i == topLF) {
					if (topLF < numFlechas - 1) {
						topLF++;
					}
					else {
						topLF = 0;
					}
				}
				fLFArray[i].setMover(false);
				fLFArray[i].setY(posicionOrigenY);
				printf("Llego al final, topLF: %d\n", topLF);
			}
		}
	}
	for (int i = 0; i < numFlechas; i++) {
		if (fUPArray[i].getMover()) {
			if (fUPArray[i].getY() < posicionMaxY) {
				fUPArray[i].incY(velocidad);
				fUPArray[i].dibujar();
			}
			else {
				if (i == topUP) {
					if (topUP < numFlechas - 1) {
						topUP++;
					}
					else {
						topUP = 0;
					}
				}
				fUPArray[i].setMover(false);
				fUPArray[i].setY(posicionOrigenY);
				printf("Llego al final, topUP: %d\n", topUP);
			}
		}
	}
	for (int i = 0; i < numFlechas; i++) {
		if (fDWArray[i].getMover()) {
			if (fDWArray[i].getY() < posicionMaxY) {
				fDWArray[i].incY(velocidad);
				fDWArray[i].dibujar();
			}
			else {
				if (i == topDW) {
					if (topDW < numFlechas - 1) {
						topDW++;
					}
					else {
						topDW = 0;
					}
				}
				fDWArray[i].setMover(false);
				fDWArray[i].setY(posicionOrigenY);
				printf("Llego al final, topDW: %d\n", topDW);
			}
		}
	}
	for (int i = 0; i < numFlechas; i++) {
		if (fRTArray[i].getMover()) {
			if (fRTArray[i].getY() < posicionMaxY) {
				fRTArray[i].incY(velocidad);
				fRTArray[i].dibujar();
			}
			else {
				if (i == topRT) {
					if (topRT < numFlechas - 1) {
						topRT++;
					}
					else {
						topRT = 0;
					}
				}
				fRTArray[i].setMover(false);
				fRTArray[i].setY(posicionOrigenY);
				printf("Llego al final, topRT: %d\n", topRT);
			}
		}
	}
}

void obtenerPuntos(float y) {
	//Perfecto 10 PTS
	if (y >= (metaY - t1) && y <= (metaY + t1)) {
		score += 10;
	}
	//Muy bien 8 PTS
	if ((y >= (metaY - t2) && y < (metaY - t1)) || (y > (metaY + t1) && y <= (metaY + t2))) {
		score += 8;
	}
	//Bien 6 PTS
	if ((y >= (metaY - t3) && y < (metaY - t2)) || (y > (metaY + t2) && y <= (metaY + t3))) {
		score += 6;
	}
	//OK 4 PTS
	if ((y >= (metaY - t4) && y < (metaY - t3)) || (y > (metaY + t3) && y <= (metaY + t4))) {
		score += 4;
	}
	//Casi 2 PTS
	if ((y >= (metaY - t5) && y < (metaY - t4)) || (y > (metaY + t4) && y <= (metaY + t5))) {
		score += 2;
	}
	//Boo 2 PTS
	if ((y >= (metaY - t6) && y < (metaY - t5)) || (y > (metaY + t5) && y <= (metaY + t6))) {
		score += 1;
	}
}


void calificarFlechaLF() {
	if (fLFArray[topLF].getMover()) {
		obtenerPuntos(fLFArray[topLF].getY());
		fLFArray[topLF].setMover(false);
		printf("Posicion LEFT %d en Y: %f\n", topLF, fLFArray[topLF].getY());
		fLFArray[topLF].setY(posicionOrigenY);
		if (topLF < numFlechas - 1) {
			topLF++;
		}
		else {
			topLF = 0;
		}
		printf("topLF: %d\n", topLF);
	}
}

void calificarFlechaUP() {
	if (fUPArray[topUP].getMover()) {
		obtenerPuntos(fUPArray[topUP].getY());
		fUPArray[topUP].setMover(false);
		printf("Posicion UP %d en Y: %f\n", topUP, fUPArray[topUP].getY());
		fUPArray[topUP].setY(posicionOrigenY);
		if (topUP < numFlechas - 1) {
			topUP++;
		}
		else {
			topUP = 0;
		}
		printf("topLF: %d\n", topUP);
	}
}

void calificarFlechaDW() {
	if (fDWArray[topDW].getMover()) {
		obtenerPuntos(fDWArray[topDW].getY());
		fDWArray[topDW].setMover(false);
		printf("Posicion DOWN %d en Y: %f\n", topDW, fDWArray[topDW].getY());
		fDWArray[topDW].setY(posicionOrigenY);
		if (topDW < numFlechas - 1) {
			topDW++;
		}
		else {
			topDW = 0;
		}
		printf("topDW: %d\n", topDW);
	}
}

void calificarFlechaRT() {
	if (fRTArray[topRT].getMover()) {
		obtenerPuntos(fRTArray[topRT].getY());
		fRTArray[topRT].setMover(false);
		printf("Posicion RIGHT %d en Y: %f\n", topRT, fRTArray[topRT].getY());
		fRTArray[topRT].setY(posicionOrigenY);
		if (topRT < numFlechas - 1) {
			topRT++;
		}
		else {
			topRT = 0;
		}
		printf("topRT: %d\n", topRT);
	}
}

void incTopDW() {
	if (topDW < numFlechas - 1) {
		topDW++;
	}
	else {
		topDW = 0;
	}
}

void agregarFlechaLF(int n) {
	fLFArray[n].setMover(true);
}

void agregarFlechaUP(int n) {
	fUPArray[n].setMover(true);
}

void agregarFlechaDW(int n) {
	fDWArray[n].setMover(true);
}

void agregarFlechaRT(int n) {
	fRTArray[n].setMover(true);
}


void finishLevel(int) {
	/*MessageBoxA(NULL, "Nivel terminado", "TecoAdventures", 0);
	exit(0);*/
	
}

void idle() {
}

void controlesJuego(unsigned char key, int x, int y) {
	switch (key) {
	case 27: //Esc
		exit(1);
		break;
	}
}

void controlesEspecial(int key, int x, int y) {
	switch (key)
	{
	case GLUT_KEY_UP:
		calificarFlechaUP();
		break;
	case GLUT_KEY_DOWN:
		calificarFlechaDW();
		break;
	case GLUT_KEY_RIGHT:
		calificarFlechaRT();
		break;
	case GLUT_KEY_LEFT:
		calificarFlechaLF();
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

	void cargarImagenes(const std::string & nombre1, const std::string & ruta1,
		const std::string & nombre2, const std::string & ruta2,
		const std::string & nombre3, const std::string & ruta3) {
		gestorRecursos->cargarTextura(nombre1, ruta1.c_str());
		gestorRecursos->cargarTextura(nombre2, ruta2.c_str());
		gestorRecursos->cargarTextura(nombre3, ruta3.c_str());

		// Agregar imágenes al vector en lugar de sobrescribirlo
		if (std::find(imagenes.begin(), imagenes.end(), nombre1) == imagenes.end()) {
			imagenes.push_back(nombre1);
		}
		if (std::find(imagenes.begin(), imagenes.end(), nombre2) == imagenes.end()) {
			imagenes.push_back(nombre2);
		}
		if (std::find(imagenes.begin(), imagenes.end(), nombre3) == imagenes.end()) {
			imagenes.push_back(nombre3);
		}
	}
