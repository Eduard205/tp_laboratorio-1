/*
 * calculos.c
 * Desarrollo de Funciones para calcular.
 * Eduard Brito Hernandez - Divisi?n 1-E
 *
 */

int sumar(int numero1, int numero2) {
	int suma;
	suma = numero1 + numero2;
	return suma;
}

int restar(int numero1, int numero2) {
	int resta;
	resta = numero1 - numero2;
	return resta;
}

float dividir(int numero1, int numero2) {
	float division;
	division = (float) numero1 / numero2;
	return division;
}

int multiplicar(int numero1, int numero2) {
	int producto;
	producto = numero1 * numero2;
	return producto;
}

int factorial(int numero) {
	int cont;
	int factorial = 1;

	if (numero < 0) {
		numero *= -1;
		for (cont = 1; cont <= numero; cont++) {
			factorial *= cont;
		}
	} else {
		for (cont = 1; cont <= numero; cont++) {
			factorial *= cont;
		}
	}
	return factorial;
}
