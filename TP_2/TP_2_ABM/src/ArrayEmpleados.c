/*
 * ArrayEmpleados.c
 *Desarrollo de funciones de la biblioteca ArrayEmpleados.h
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmpleados.h"

int inicializarEmpleado(eEmpleado array[], int tam) {
	int devolucion = -1;
	if (array != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			array[i].isEmpty = 1;
			array[i].id = 0;
			strcpy(array[i].nombre, " ");
			strcpy(array[i].apellido, " ");
			array[i].sector = 0;
			array[i].sueldo = 0;
		}
		devolucion = 0;
	}
	return devolucion;
}

int buscarLibre(eEmpleado array[], int *posicion, int tam) {

	int rtn = -1;
	if (array != NULL && posicion != NULL && tam > 0) {

		for (int i = 0; i < tam; i++) {
			if (array[i].isEmpty == 1) {
				*posicion = i;
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}

int altaEmpleado(eEmpleado array[], int posicion, int *contadorId) {

	array[posicion].id = *contadorId;

	printf("Ingrese nombre: ");
	fflush(stdin);
	gets(array[posicion].nombre);

	printf("Ingrese apellido: ");
	fflush(stdin);
	gets(array[posicion].apellido);

	printf("Ingrese sector: ");
	scanf("%d", &array[posicion].sector);

	printf("Ingrese sueldo: ");
	scanf("%f", &array[posicion].sueldo);

	array[posicion].isEmpty = 0;

	printf("Id empleado: %d\n", array[posicion].id);
	printf("Nombre: %s\n", array[posicion].nombre);
	printf("Apellido: %s\n", array[posicion].apellido);
	printf("Sector: %d\n", array[posicion].sector);
	printf("Sueldo: %.2f\n", array[posicion].sueldo);
	printf("isEmpty: %d\n", array[posicion].isEmpty);

	return 0;
}

int buscarEmpleado(eEmpleado array[], int tam, int id) {
	int rtn = -1;
	int i;

	if (array != NULL && tam > 0) {
		for (i = 0; i < tam; i++) {
			if (array[i].id == id && array[i].isEmpty == 0) {
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}

eEmpleado modificarUnEmpleado(eEmpleado array) {

	printf("Ingrese nombre: ");
	fflush(stdin);
	gets(array.nombre);

	printf("Ingrese apellido: ");
	fflush(stdin);
	gets(array.apellido);

	printf("Ingrese sector: ");
	scanf("%d", &array.sector);

	printf("Ingrese sueldo: ");
	scanf("%f", &array.sueldo);

	eEmpleado arrayAux = array;
	return arrayAux;
}

int modificarEmpleado(eEmpleado array[], int tam) {

	int rtn = 0;
	int posicion;
	int idEmpleado;
	eEmpleado arrayAux;

	printf("Ingrese el id del empleado a modificar: ");
	scanf("%d", &idEmpleado);
	while (idEmpleado < 1 || idEmpleado > 1000) {
		printf("Error. Ingrese un Id de empleado entre (1-1000): ");
		scanf("%d", &idEmpleado);
	}

	while (buscarEmpleado(array, tam, idEmpleado) == -1) {
		printf("No existe el id ingresado, reingrese id del empleado: ");
		scanf("%d", &idEmpleado);
	}

	posicion = buscarEmpleado(array, tam, idEmpleado);

	arrayAux = modificarUnEmpleado(array[posicion]);

	array[posicion] = arrayAux;

	rtn = 1;
	if (rtn == 1) {
		printf("Se modifico los datos del empleado\n");
		printf("Nuevo Nombre: %s\n", array[posicion].nombre);
		printf("Nuevo Apellido: %s\n", array[posicion].apellido);
		printf("Nuevo Sector: %d\n", array[posicion].sector);
		printf("Nuevo Sueldo: %.2f\n", array[posicion].sueldo);
	}

	return rtn;
}

int bajaEmpleado(eEmpleado array[], int tam) {

	int rtn = 0;
	int posicion;
	int idEmpleado;


	printf("Ingrese el id del empleado a eliminar: ");
	scanf("%d", &idEmpleado);
	while (idEmpleado < 1 || idEmpleado > 1000) {
		printf("Error. Ingrese un Id de empleado entre (1-1000): ");
		scanf("%d", &idEmpleado);
	}

	while (buscarEmpleado(array, tam, idEmpleado) == -1) {
		printf("No existe el id ingresado, reingrese id del empleado: ");
		scanf("%d", &idEmpleado);
	}

	posicion = buscarEmpleado(array, tam, idEmpleado);

	array[posicion].isEmpty=-1;

	rtn = 1;

	if (rtn == 1) {
		printf("Se elimino al empleado con el id %d\n", array[posicion].id);
		printf("Nombre: %s\n", array[posicion].nombre);
		printf("Apellido: %s\n", array[posicion].apellido);
		printf("Sector: %d\n", array[posicion].sector);
		printf("Sueldo: %.2f\n", array[posicion].sueldo);
	}

	return rtn;
}

void mostrarUnEmpleado(eEmpleado array) {

	printf("%5d%10s%10s%7d%13.2f\n", array.id, array.nombre, array.apellido, array.sector, array.sueldo);

}

int mostrarEmpleados(eEmpleado array[], int tam) {
	int i;
	int rtn = 0;


	printf("\n\t> LISTADO EMPLEADOS\n");
	printf("%5s%10s%10s%10s%9s\n", "ID","NOMBRE","APELLIDO","SECTOR","SUELDO");


	if (array != NULL && tam > 0) {
		for (i = 0; i < tam; i++) {
			if (array[i].isEmpty== 0) {
				mostrarUnEmpleado(array[i]);
				rtn++;
			}
		}

	}
	return rtn;
}

int ordenarEmpleados(eEmpleado array[], int tam, int criterio){

	int rtn = 0;
	int i;
	int j;
	eEmpleado aux;

	if (array != NULL && tam > 0) {
		switch (criterio) {
		case -1:
			for (i = 0; i < tam - 1; i++) {
				for (j = i + 1; j < tam; j++) {
					if (array[i].isEmpty== 0 && array[j].isEmpty== 0) {
						if (array[i].sector > array[j].sector) {
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		case 1:
			for (i = 0; i < tam - 1; i++) {
				for (j = i + 1; j < tam; j++) {
					if (array[i].isEmpty== 0 && array[j].isEmpty== 0) {
						if (array[i].sector < array[j].sector) {
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		default:
			rtn = 0;
			break;
		}
	}
return rtn;
}
