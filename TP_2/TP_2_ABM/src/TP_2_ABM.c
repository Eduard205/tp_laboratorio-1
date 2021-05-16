/*
 ============================================================================
 Name        : TP_2_ABM.c
 Author      : Eduard Brito Hernandez - División: 1-E
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
	int criterioDeOrdenamiento;
	int flagOpcion1 = 0;



	inicializarEmpleado(listaEmpleados, TAM);



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
						"Ingreso una opción invalida, las opciones disponibles son (1, 2, 3, 4, 5): ");
				scanf("%d", &opcion);
			}

			switch (opcion) {

			case 1:
				 if(buscarLibre(listaEmpleados, &posicion, TAM) != -1)
					{
						altaEmpleado(listaEmpleados, posicion, &contadorId);
						contadorId++;
						flagOpcion1 = 1;
					}
				break;


			case 2:
				if(flagOpcion1 ==1){
				modificarEmpleado(listaEmpleados, TAM);
				}
				else{
					printf("No ha dado de alta empleados, ingrese a la opción 1");
				}
				break;

			case 3:
				if(flagOpcion1 ==1){
				bajaEmpleado(listaEmpleados, TAM);
				}
				else{
					printf("No ha dado de alta empleados, ingrese a la opción 1");
				}
				break;
			case 4:
				if(flagOpcion1 ==1){
				printf("\nIngrese criterio de ordenamiento:"
						"\n1-Ordenar de forma descendente lista de empleados por sector"
						"\n-1-Ordenar de forma ascendente lista de empleados por sector");

				scanf("%d", &criterioDeOrdenamiento);

								while (criterioDeOrdenamiento!= 1 && criterioDeOrdenamiento!=-1) {
								printf("Ingreso un criterio valido, las opciones disponibles son (1 o -1): ");
								scanf("%d", &criterioDeOrdenamiento);
										}

				ordenarEmpleados(listaEmpleados, TAM, criterioDeOrdenamiento);
				if(mostrarEmpleados(listaEmpleados, TAM)){
					system("pause");
				}
				else{
						printf("No hay empleados para mostrar");
				}
				}
				else{
				printf("No ha dado de alta empleados, ingrese a la opción 1");
				}
				break;


			case 5:
				printf("A salido del programa");
				resp = !'s';
				break;

		}
	}while (resp == 's');

	return EXIT_SUCCESS;
}
