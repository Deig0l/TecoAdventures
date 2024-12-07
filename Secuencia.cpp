#include "Secuencia.h"

void secuenciaNivel1(int) {
	//LEFT
	glutTimerFunc(1000, agregarFlechaLF, 0);
	glutTimerFunc(3000, agregarFlechaLF, 1);
	glutTimerFunc(7000, agregarFlechaLF, 2);
	glutTimerFunc(12000, agregarFlechaLF, 3);
	glutTimerFunc(16000, agregarFlechaLF, 4);

	//UP
	glutTimerFunc(2000, agregarFlechaUP, 0);
	glutTimerFunc(5000, agregarFlechaUP, 1);
	glutTimerFunc(8000, agregarFlechaUP, 2);
	glutTimerFunc(9000, agregarFlechaUP, 3);
	glutTimerFunc(13000, agregarFlechaUP, 4);

	//DOWN
	glutTimerFunc(1500, agregarFlechaDW, 0);
	glutTimerFunc(6000, agregarFlechaDW, 1);
	glutTimerFunc(11000, agregarFlechaDW, 2);
	glutTimerFunc(15000, agregarFlechaDW, 3);
	glutTimerFunc(17000, agregarFlechaDW, 4);

	//RIGHT
	glutTimerFunc(4000, agregarFlechaRT, 0);
	glutTimerFunc(7000, agregarFlechaRT, 1);
	glutTimerFunc(8500, agregarFlechaRT, 2);
	glutTimerFunc(10000, agregarFlechaRT, 3);
	glutTimerFunc(14000, agregarFlechaRT, 4);

	//Finish game
	//glutTimerFunc(22000, finishGame, 0);
}

void secuenciaNivel2(int) {
	glutTimerFunc(1000, agregarFlechaDW, 0);
	glutTimerFunc(2500, agregarFlechaDW, 1);
	glutTimerFunc(3500, agregarFlechaDW, 2);
	glutTimerFunc(4500, agregarFlechaDW, 3);
	glutTimerFunc(5500, agregarFlechaDW, 4);
	glutTimerFunc(6500, agregarFlechaDW, 5);
	glutTimerFunc(7500, agregarFlechaDW, 6);
	glutTimerFunc(8500, agregarFlechaDW, 7);
	glutTimerFunc(9500, agregarFlechaDW, 8);
	glutTimerFunc(11000, agregarFlechaDW, 9);
	glutTimerFunc(12000, agregarFlechaDW, 0);
	glutTimerFunc(13000, agregarFlechaDW, 1);
	glutTimerFunc(14000, agregarFlechaDW, 2);
	glutTimerFunc(15000, agregarFlechaDW, 3);
	glutTimerFunc(16000, agregarFlechaDW, 4);
	glutTimerFunc(17500, agregarFlechaDW, 5);
	glutTimerFunc(18500, agregarFlechaDW, 6);
	glutTimerFunc(20000, agregarFlechaDW, 7);
	glutTimerFunc(21000, agregarFlechaDW, 8);
	glutTimerFunc(21500, agregarFlechaDW, 9);

	//Finish game
	//glutTimerFunc(25500, finishGame, 0);
}

void secuenciaNivel3(int) {
	glutTimerFunc(1000, agregarFlechaUP, 0);
	glutTimerFunc(1500, agregarFlechaLF, 0);
	glutTimerFunc(2500, agregarFlechaRT, 0);
	glutTimerFunc(3000, agregarFlechaDW, 0);
	glutTimerFunc(3500, agregarFlechaUP, 1);
	glutTimerFunc(4000, agregarFlechaLF, 1);
	glutTimerFunc(4000, agregarFlechaRT, 1);
	glutTimerFunc(5000, agregarFlechaDW, 1);
	glutTimerFunc(6000, agregarFlechaUP, 2);
	glutTimerFunc(7000, agregarFlechaDW, 2);
	glutTimerFunc(7000, agregarFlechaLF, 2);
	glutTimerFunc(8000, agregarFlechaUP, 3);
	glutTimerFunc(8000, agregarFlechaRT, 2);
	glutTimerFunc(9000, agregarFlechaDW, 3);
	glutTimerFunc(10000, agregarFlechaLF, 3);
	glutTimerFunc(11000, agregarFlechaUP, 4);
	glutTimerFunc(12000, agregarFlechaLF, 4);
	glutTimerFunc(12000, agregarFlechaRT, 3);
	glutTimerFunc(13000, agregarFlechaDW, 4);
	glutTimerFunc(14500, agregarFlechaRT, 4);

	//Finish game
	//glutTimerFunc(19500, finishGame, 0);
}
