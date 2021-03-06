/*
 ============================================================================
 Name        : TP_1_CALCULADORA.c
 Author      : Eduard Amilcar Brito Hernandez - Divisi?n 1-E

 Hacer una calculadora. Para ello el programa iniciar? y contar? con un men? de opciones:

 1.  Ingresar 1er operando (A=x)

 2.  Ingresar 2do operando (B=y)

 3.  Calcular todas las operaciones
 a)  Calcular la suma (A+B)
 b)  Calcular la resta (A-B)
 c)  Calcular la division (A/B)
 d)  Calcular la multiplicacion (A*B)
 e)  Calcular el factorial (A!)

 4.  Informar resultados
 a)  ?El resultado de A+B es: r?
 b)  ?El resultado de A-B es: r?
 c)  ?El resultado de A/B es: r? o ?No es posible dividir por cero?
 d)  ?El resultado de A*B es: r?
 e)  ?El factorial de A es: r1 y El factorial de B es: r2?

 5.  Salir

 ? Todas las funciones matem?ticas del men? se deber?n realizar en una biblioteca aparte, que contenga las funciones para realizar las cinco operaciones.
 ? En el men? deber?n aparecer los valores actuales cargados en los operandos A y B (donde dice ?x? e ?y? en el ejemplo, se debe mostrar el n?mero cargado).
 ? Deber?n contemplarse los casos de error (divisi?n por cero, etc).
 ? Documentar todas las funciones.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"

int main(void) {
	setbuf(stdout, NULL);

	int primerOperando;
	int segundoOperando;
	int opcion;
	char resp = 's';
	int flagOpcion1 = 0;
	int flagOpcion2 = 0;
	int flagOpcion3 = 0;
	int flagDivision = 0;
	int resulSuma = 0;
	int resulResta = 0;
	int resulProducto = 0;
	float resulDivision = 0;
	int resulFactorial1;
	int resulFactorial2;

	do {
		printf("\nIngrese una opcion del menu (1, 2, 3, 4, 5):"
				"\n1-Ingresar primer operando"
				"\n2-Ingresar segundo operando"
				"\n3-Calcular todas las operaciones"
				"\n4-Informar resultados"
				"\n5-Salir\n");
		scanf("%d", &opcion);

		while (opcion < 1 || opcion > 5) {
			printf(
					"Ingreso una opci?n invalida, las opciones disponibles son (1, 2, 3, 4, 5): ");
			scanf("%d", &opcion);
		}

		switch (opcion) {

		case 1:
			printf("Ingresar primer operando: ");
			scanf("%d", &primerOperando);
			flagOpcion1 = 1;
			printf("Primer operando ingresado: %d\n", primerOperando);
			break;

		case 2:
			printf("Ingresar segundo operando: ");
			scanf("%d", &segundoOperando);
			flagOpcion2 = 1;
			printf("Segundo operando ingresado: %d\n", segundoOperando);
			break;

		case 3:
			if (flagOpcion1 == 0 || flagOpcion2 == 0) {
				printf("Para calcular debe ingresar los dos operandos\n");
			} else {
				resulSuma = sumar(primerOperando, segundoOperando);
				resulResta = restar(primerOperando, segundoOperando);
				resulProducto = multiplicar(primerOperando, segundoOperando);
				resulFactorial1 = factorial(primerOperando);
				resulFactorial2 = factorial(segundoOperando);
				if (segundoOperando != 0) {
					resulDivision = dividir(primerOperando, segundoOperando);
					flagDivision = 1;
				}

				printf("Se calcularon todas las operaciones\n");
				flagOpcion3 = 1;
			}
			break;

		case 4:
			if (flagOpcion1 == 0 || flagOpcion2 == 0) {
				printf(
						"Debe ingresar los dos operandos para informar resultados\n");
			} else {
				if (flagOpcion3 == 0) {
					printf(
							"Para informar resultados primero debe seleccionar la opcion 3 (Calcular todas las operaciones)\n");
				} else {
					printf("a) El resultado de %d + %d es: %d\n",
							primerOperando, segundoOperando, resulSuma);
					printf("b) El resultado de %d - %d es: %d\n",
							primerOperando, segundoOperando, resulResta);
					if (flagDivision == 1) {
						printf("c) El resultado de %d / %d es: %.2f\n",
								primerOperando, segundoOperando, resulDivision);
					} else {
						printf("c) No se puede dividir entre '0' \n");
					}
					printf("d) El resultado de %d * %d es: %d\n",
							primerOperando, segundoOperando, resulProducto);
					printf(
							"e) El factorial de %d es: %d y El factorial de %d es: %d\n",
							primerOperando, resulFactorial1, segundoOperando,
							resulFactorial2);
				}
			}
			break;

		case 5:
			printf("A salido del programa");
			resp = !'s';
			break;
		}

	} while (resp == 's');

	return EXIT_SUCCESS;
}
