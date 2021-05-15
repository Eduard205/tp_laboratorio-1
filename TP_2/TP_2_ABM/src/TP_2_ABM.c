/*
 ============================================================================
 Name        : TP_2_ABM.c
 Author      : Eduard Brito Hernandez - Divisi�n: 1-E
 Version     : Nomina de empleados
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmpleados.h"
#define TAM 2

int main(void) {
	setbuf(stdout, NULL);

	eEmpleado listaEmpleados[TAM];
	int opcion;
	char resp = 's';
	int posicion;
	int contadorId=1;

	inicializarEmpleado(listaEmpleados, TAM);

	//mostrarInicializacion(listaEmpleados, TAM);


	do {
			printf("\nIngrese una opcion del menu:"
					"\n1-Alta de empleado"
					"\n2-Modificar empleado"
					"\n3-Baja empleado"
					"\n4-Informes"
					"\n5-Salir\n");
			scanf("%d", &opcion);

			while (opcion < 1 || opcion > 5) {
				printf(
						"Ingreso una opci�n invalida, las opciones disponibles son (1, 2, 3, 4, 5): ");
				scanf("%d", &opcion);
			}

			switch (opcion) {

			case 1:
				 if(buscarLibre(listaEmpleados, &posicion, TAM) != -1)
					{
						altaEmpleado(listaEmpleados, posicion, &contadorId);
						contadorId++;
					}
				break;
				//flagOpcion1 = 1;

				break;

			case 2:
				//buscarLibre(listaAlumnos,&posicion,TAM);
				//printf("posicion: %d",posicion);
				//	break;

			case 3:

			case 4:

			case 5:
				printf("A salido del programa");
				resp = !'s';
				break;
			}

		} while (resp == 's');

	return EXIT_SUCCESS;
}