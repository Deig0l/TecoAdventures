#include "Secuencia.h"

void secuenciaNivel1(int) {
	glutTimerFunc(0, agregarFlechaLF, 0);
	glutTimerFunc(1000, agregarFlechaDW, 0);
	glutTimerFunc(2000, agregarFlechaUP, 0);
	glutTimerFunc(2800, agregarFlechaLF, 1);
	glutTimerFunc(3000, agregarFlechaRT, 0);
	glutTimerFunc(4000, agregarFlechaRT, 1);
	glutTimerFunc(5000, agregarFlechaUP, 1);
	glutTimerFunc(6000, agregarFlechaDW, 1);
	glutTimerFunc(7000, agregarFlechaUP, 2);
	glutTimerFunc(8000, agregarFlechaLF, 2);
	glutTimerFunc(8000, agregarFlechaRT, 2);
	glutTimerFunc(9000, agregarFlechaDW, 2);
	glutTimerFunc(9500, agregarFlechaLF, 3);
	glutTimerFunc(10500, agregarFlechaUP, 3);
	glutTimerFunc(11000, agregarFlechaRT, 3);
	glutTimerFunc(11500, agregarFlechaLF, 4);
	glutTimerFunc(12000, agregarFlechaUP, 4);
	glutTimerFunc(12300, agregarFlechaDW, 3);

	glutTimerFunc(14500, agregarFlechaRT, 4);
	glutTimerFunc(14500, agregarFlechaDW, 4);
	glutTimerFunc(15500, agregarFlechaLF, 5);
	glutTimerFunc(15500, agregarFlechaUP, 5);
	glutTimerFunc(16500, agregarFlechaDW, 5);
	glutTimerFunc(17500, agregarFlechaUP, 6);
	
	glutTimerFunc(18500, agregarFlechaRT, 5);
	glutTimerFunc(18700, agregarFlechaDW, 6);
	glutTimerFunc(18900, agregarFlechaUP, 7);
	glutTimerFunc(19100, agregarFlechaLF, 6);

	glutTimerFunc(20000, agregarFlechaUP, 8);
	glutTimerFunc(21000, agregarFlechaDW, 7);
	
	glutTimerFunc(22000, agregarFlechaLF, 7);
	glutTimerFunc(22300, agregarFlechaDW, 8);

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
