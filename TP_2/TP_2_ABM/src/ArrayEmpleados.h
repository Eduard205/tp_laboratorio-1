/*
 * ArrayEmpleados.h
 *Agrupa funciones que permiten trabajar con los datos almacenados en la estructura Empleados,
 *la cual representa los datos de un empleado de la empresa.
 *
 */

#ifndef ARRAYEMPLEADOS_H_
#define ARRAYEMPLEADOS_H_

typedef struct {
	int id;
	char nombre[51];
	char apellido[51];
	float sueldo;
	int sector;
	int isEmpty;
} eEmpleado;

int inicializarEmpleado(eEmpleado array[], int tam);

//int mostrarInicializacion(eEmpleado array[], int tam);

int buscarLibre(eEmpleado array[], int *posicion, int tam);

int altaEmpleado(eEmpleado array[], int posicion, int* contadorId);

#endif /* ARRAYEMPLEADOS_H_ */
