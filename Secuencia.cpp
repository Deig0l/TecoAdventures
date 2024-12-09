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

	glutTimerFunc(24300, agregarFlechaRT, 6);
	glutTimerFunc(24500, agregarFlechaUP, 9);
	glutTimerFunc(25300, agregarFlechaLF, 8);
	glutTimerFunc(25500, agregarFlechaDW, 9);

	glutTimerFunc(26000, agregarFlechaRT, 7);
	glutTimerFunc(27000, agregarFlechaRT, 8);

	glutTimerFunc(28000, agregarFlechaLF, 9);
	glutTimerFunc(28000, agregarFlechaRT, 9);
	glutTimerFunc(29000, agregarFlechaUP, 0);
	glutTimerFunc(29000, agregarFlechaDW, 0);

	glutTimerFunc(30000, agregarFlechaLF, 0);
	glutTimerFunc(30500, agregarFlechaRT, 0);
	glutTimerFunc(31000, agregarFlechaLF, 1);
	glutTimerFunc(31500, agregarFlechaRT, 1);

	//Finish game
	//glutTimerFunc(22000, finishGame, 0);
}

void secuenciaNivel2(int) {
	glutTimerFunc(0, agregarFlechaDW, 0); 
	glutTimerFunc(500, agregarFlechaLF, 0);
	glutTimerFunc(1000, agregarFlechaRT, 0);
	glutTimerFunc(1500, agregarFlechaRT, 1);
	glutTimerFunc(2000, agregarFlechaRT, 2);
	glutTimerFunc(2500, agregarFlechaUP, 0);
	glutTimerFunc(2800, agregarFlechaRT, 3);
	glutTimerFunc(3100, agregarFlechaDW, 1);
	glutTimerFunc(3400, agregarFlechaLF, 1);
	glutTimerFunc(4000, agregarFlechaUP, 1);
	glutTimerFunc(4000, agregarFlechaDW, 2);
	glutTimerFunc(4500, agregarFlechaLF, 2);
	glutTimerFunc(4500, agregarFlechaRT, 4);
	glutTimerFunc(5000, agregarFlechaUP, 2);
	glutTimerFunc(5000, agregarFlechaDW, 3);
	glutTimerFunc(5500, agregarFlechaLF, 3);
	glutTimerFunc(5500, agregarFlechaRT, 5);
	glutTimerFunc(7000, agregarFlechaUP, 3);
	glutTimerFunc(7500, agregarFlechaUP, 4);
	glutTimerFunc(8000, agregarFlechaLF, 3);
	glutTimerFunc(8200, agregarFlechaDW, 4);
	glutTimerFunc(8400, agregarFlechaLF, 4);
	glutTimerFunc(8600, agregarFlechaUP, 5);

	glutTimerFunc(10000, agregarFlechaDW, 5);
	glutTimerFunc(10000, agregarFlechaLF, 5);
	glutTimerFunc(10500, agregarFlechaRT, 6);
	glutTimerFunc(10500, agregarFlechaUP, 6);

	glutTimerFunc(11000, agregarFlechaDW, 6);
	glutTimerFunc(11000, agregarFlechaRT, 7);
	glutTimerFunc(11500, agregarFlechaUP, 7);
	glutTimerFunc(11500, agregarFlechaLF, 6);
	
	glutTimerFunc(12000, agregarFlechaLF, 7);
	glutTimerFunc(12300, agregarFlechaUP, 8);
	glutTimerFunc(12600, agregarFlechaDW, 7);
	glutTimerFunc(12900, agregarFlechaRT, 8);
	glutTimerFunc(13200, agregarFlechaUP, 9);
	glutTimerFunc(13500, agregarFlechaDW, 8);
	glutTimerFunc(13800, agregarFlechaRT, 9);

	glutTimerFunc(15000, agregarFlechaRT, 0);
	glutTimerFunc(15300, agregarFlechaDW, 9);
	glutTimerFunc(15600, agregarFlechaUP, 0);
	glutTimerFunc(15900, agregarFlechaLF, 8);
	glutTimerFunc(16200, agregarFlechaDW, 0);
	glutTimerFunc(16500, agregarFlechaUP, 1);
	glutTimerFunc(16800, agregarFlechaLF, 9);

	glutTimerFunc(18000, agregarFlechaLF, 0);
	glutTimerFunc(18000, agregarFlechaRT, 1);
	glutTimerFunc(18500, agregarFlechaLF, 1);
	glutTimerFunc(18500, agregarFlechaRT, 2);

	glutTimerFunc(19000, agregarFlechaUP, 2);
	glutTimerFunc(19500, agregarFlechaDW, 1);
	glutTimerFunc(20000, agregarFlechaDW, 2);
	glutTimerFunc(20500, agregarFlechaUP, 3);

	glutTimerFunc(21000, agregarFlechaLF, 2);
	glutTimerFunc(21000, agregarFlechaRT, 2);
	glutTimerFunc(21500, agregarFlechaLF, 3);
	glutTimerFunc(21500, agregarFlechaRT, 3);

	glutTimerFunc(23000, agregarFlechaUP, 4);
	glutTimerFunc(23300, agregarFlechaRT, 4);
	glutTimerFunc(23600, agregarFlechaDW, 3);
	glutTimerFunc(23900, agregarFlechaLF, 4);

	glutTimerFunc(25000, agregarFlechaUP, 5);
	glutTimerFunc(25000, agregarFlechaRT, 5);
	glutTimerFunc(25500, agregarFlechaUP, 6);
	glutTimerFunc(25500, agregarFlechaRT, 6);

	glutTimerFunc(26000, agregarFlechaDW, 4);
	glutTimerFunc(26000, agregarFlechaLF, 5);
	glutTimerFunc(26500, agregarFlechaDW, 5);
	glutTimerFunc(26500, agregarFlechaLF, 6);

	glutTimerFunc(28000, agregarFlechaLF, 7);
	glutTimerFunc(28500, agregarFlechaDW, 6);
	glutTimerFunc(29000, agregarFlechaUP, 7);
	glutTimerFunc(29500, agregarFlechaLF, 8);
	glutTimerFunc(30000, agregarFlechaRT, 7);
	glutTimerFunc(30500, agregarFlechaRT, 8);
	glutTimerFunc(31000, agregarFlechaUP, 8);
	glutTimerFunc(31500, agregarFlechaDW, 7);
	glutTimerFunc(32000, agregarFlechaUP, 9);
	glutTimerFunc(32500, agregarFlechaLF, 9);
	glutTimerFunc(33000, agregarFlechaRT, 9);
	glutTimerFunc(33500, agregarFlechaDW, 8);
	glutTimerFunc(34000, agregarFlechaLF, 0);
	glutTimerFunc(34500, agregarFlechaUP, 0);
	glutTimerFunc(35000, agregarFlechaRT, 0);
	glutTimerFunc(35500, agregarFlechaLF, 1);
	glutTimerFunc(36000, agregarFlechaUP, 1);
	glutTimerFunc(36500, agregarFlechaDW, 9);

	//Finish game
	//glutTimerFunc(25500, finishGame, 0);
}

void secuenciaNivel3(int) {
	glutTimerFunc(0, agregarFlechaRT, 0);
	glutTimerFunc(0, agregarFlechaDW, 0);
	glutTimerFunc(500, agregarFlechaLF, 0);
	glutTimerFunc(500, agregarFlechaUP, 0);
	glutTimerFunc(1000, agregarFlechaDW, 1);
	glutTimerFunc(1500, agregarFlechaUP, 1);

	glutTimerFunc(2000, agregarFlechaRT, 1);
	glutTimerFunc(2200, agregarFlechaDW, 2);
	glutTimerFunc(2400, agregarFlechaUP, 2);
	glutTimerFunc(2600, agregarFlechaLF, 1);

	glutTimerFunc(3000, agregarFlechaUP, 3);
	glutTimerFunc(3500, agregarFlechaDW, 3);

	glutTimerFunc(4000, agregarFlechaLF, 2);
	glutTimerFunc(4500, agregarFlechaDW, 4);

	glutTimerFunc(5000, agregarFlechaUP, 4);
	glutTimerFunc(5500, agregarFlechaLF, 3);
	glutTimerFunc(6000, agregarFlechaRT, 2);
	glutTimerFunc(6500, agregarFlechaDW, 5);
	glutTimerFunc(7000, agregarFlechaUP, 5);
	glutTimerFunc(7500, agregarFlechaLF, 4);
	glutTimerFunc(8000, agregarFlechaRT, 3);
	glutTimerFunc(8500, agregarFlechaDW, 6);
	glutTimerFunc(9000, agregarFlechaUP, 6);
	glutTimerFunc(9500, agregarFlechaDW, 7);
	glutTimerFunc(9500, agregarFlechaLF, 5);
	glutTimerFunc(10000, agregarFlechaUP, 7);
	glutTimerFunc(10000, agregarFlechaRT, 4);
	glutTimerFunc(10500, agregarFlechaDW, 8);
	glutTimerFunc(11000, agregarFlechaLF, 6);
	glutTimerFunc(11500, agregarFlechaUP, 8);
	glutTimerFunc(12000, agregarFlechaLF, 7);
	glutTimerFunc(12000, agregarFlechaRT, 5);
	glutTimerFunc(12500, agregarFlechaDW, 9);
	glutTimerFunc(13000, agregarFlechaRT, 6);

	glutTimerFunc(13300, agregarFlechaLF, 8);
	glutTimerFunc(13600, agregarFlechaUP, 9);
	glutTimerFunc(13900, agregarFlechaDW, 0);
	glutTimerFunc(14200, agregarFlechaRT, 7);
	glutTimerFunc(14500, agregarFlechaUP, 0);
	glutTimerFunc(14800, agregarFlechaDW, 1);
	glutTimerFunc(15100, agregarFlechaRT, 8);

	glutTimerFunc(15500, agregarFlechaRT, 9);
	glutTimerFunc(16000, agregarFlechaDW, 2);
	glutTimerFunc(16500, agregarFlechaUP, 1);
	glutTimerFunc(17000, agregarFlechaLF, 9);
	glutTimerFunc(17500, agregarFlechaDW, 3);
	glutTimerFunc(18000, agregarFlechaUP, 2);
	glutTimerFunc(18500, agregarFlechaLF, 0);

	glutTimerFunc(19000, agregarFlechaUP, 3);
	glutTimerFunc(19500, agregarFlechaLF, 1);
	glutTimerFunc(20000, agregarFlechaRT, 0);
	glutTimerFunc(20500, agregarFlechaDW, 4);
	glutTimerFunc(21000, agregarFlechaUP, 4);
	glutTimerFunc(21500, agregarFlechaLF, 2);
	glutTimerFunc(22000, agregarFlechaRT, 1);
	glutTimerFunc(22500, agregarFlechaDW, 5);
	glutTimerFunc(23000, agregarFlechaUP, 5);
	glutTimerFunc(23500, agregarFlechaDW, 6);
	glutTimerFunc(23500, agregarFlechaLF, 3);
	glutTimerFunc(24000, agregarFlechaUP, 6);
	glutTimerFunc(24000, agregarFlechaRT, 2);
	glutTimerFunc(24500, agregarFlechaDW, 7);
	glutTimerFunc(25000, agregarFlechaLF, 4);
	glutTimerFunc(25500, agregarFlechaUP, 7);
	glutTimerFunc(26000, agregarFlechaLF, 5);
	glutTimerFunc(26000, agregarFlechaRT, 3);
	glutTimerFunc(26500, agregarFlechaDW, 8);
	glutTimerFunc(27000, agregarFlechaRT, 4);
	
	glutTimerFunc(27500, agregarFlechaLF, 6);
	glutTimerFunc(27500, agregarFlechaRT, 5);
	glutTimerFunc(28000, agregarFlechaLF, 7);
	glutTimerFunc(28000, agregarFlechaRT, 6);

	glutTimerFunc(28500, agregarFlechaUP, 8);
	glutTimerFunc(28800, agregarFlechaRT, 7);
	glutTimerFunc(29100, agregarFlechaDW, 9);
	glutTimerFunc(29400, agregarFlechaLF, 8);

	glutTimerFunc(30000, agregarFlechaUP, 9);
	glutTimerFunc(30000, agregarFlechaRT, 8);
	glutTimerFunc(30500, agregarFlechaUP, 0);
	glutTimerFunc(30500, agregarFlechaRT, 9);

	glutTimerFunc(31000, agregarFlechaDW, 0);
	glutTimerFunc(31000, agregarFlechaLF, 9);
	glutTimerFunc(31500, agregarFlechaDW, 1);
	glutTimerFunc(31500, agregarFlechaLF, 0);

	//Finish game
	//glutTimerFunc(19500, finishGame, 0);
}
