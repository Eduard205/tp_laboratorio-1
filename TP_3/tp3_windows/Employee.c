#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Employee.h"


Employee* employee_new() {
	return (Employee*) malloc(sizeof(Employee));
}

void employee_delete(Employee* this){

	if(this != NULL)
	{
		free(this);
	}
}

Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr){
	void *rtn = NULL;

	Employee* pEmployee = employee_new();

	if( idStr != NULL && nombreStr != NULL &&  horasTrabajadasStr != NULL && sueldoStr != NULL)
	{
		if((employee_setId(pEmployee, atoi(idStr))==0) &&
			(employee_setNombre(pEmployee, nombreStr)==0) &&
			(employee_setHorasTrabajadas( pEmployee, atoi(horasTrabajadasStr))==0) &&
			(employee_setSueldo( pEmployee, atoi(sueldoStr))==0))
			{
				rtn= pEmployee;
			}
			else
				{
					employee_delete(pEmployee);
				}
	}
	return rtn;
}

int employee_setId(Employee* this, int id){
	int rtn=-1;

		if(this != NULL && id > 0 /*&& isdigit(id)!=0*/)
		{
			this->id = id;
			rtn = 0;
		}
	return rtn;
}

int employee_getId(Employee* this, int* id){
	int rtn=-1;

		if(this != NULL && id != NULL)
		{
			*id = this->id;
			rtn = 0;
		}
	return rtn;
}

int employee_setNombre(Employee* this, char* nombre){
	int rtn=-1;

		if(this != NULL && nombre != NULL)
		{
			if(isalpha(*nombre)!=0)
			{
				strcpy(this->nombre, nombre);
				rtn = 0;
			}
		}
	return rtn;
}

int employee_getNombre(Employee* this, char* nombre){
	int rtn=-1;

		if(this != NULL && nombre != NULL)
		{
			strcpy(nombre, this->nombre);
			rtn = 0;
		}
	return rtn;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas){
	int rtn=-1;

		if(this != NULL && horasTrabajadas > -1 /*&& isdigit(horasTrabajadas)!=0*/)
		{
			this->horasTrabajadas = horasTrabajadas;
			rtn = 0;
		}
	return rtn;
}

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas){
	int rtn=-1;

		if(this != NULL && horasTrabajadas != NULL)
		{
			*horasTrabajadas = this->horasTrabajadas;
			rtn = 0;
		}
	return rtn;
}

int employee_setSueldo(Employee* this, int sueldo){
	int rtn=-1;

		if(this != NULL && sueldo > -1 /*&& isdigit(sueldo)!=0*/)
		{
			this->sueldo = sueldo;
			rtn = 0;
		}
	return rtn;
}

int employee_getSueldo(Employee* this, int* sueldo){
	int rtn=-1;

		if( this != NULL &&  sueldo != NULL)
		{
			*sueldo = this->sueldo;
			rtn = 0;
		}
	return rtn;
}

int employee_findById(LinkedList* pList, int id) {

	int rtn = -1;
	int lenLista;
	int i;
	int idAux;

	if (id > 0 && pList != NULL)
	{
		lenLista = ll_len(pList);
		for (i = 0; i < lenLista; i++)
		{
			Employee *aux = ll_get(pList, i);
			employee_getId(aux, &idAux);

			if (id == idAux)
			{
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}

void employee_ImprimirUno(Employee* this){

	printf("\n  ****************  DATOS DEL EMPLEADO  ***************** ");
	printf("\n Id %2d. Nombre: %-16s |  Horas Trabajadas: %-7d |  Sueldo: %-8d\n",
			this->id,
			this->nombre,
			this->horasTrabajadas,
			this->sueldo);
}

int employee_sortID(void* thisA, void* thisB){
	int rtn=0;
	int auxIdA;
	int auxIdB;

		if(thisA!=NULL && thisB!=NULL)
		{
			if(employee_getId(thisA, &auxIdA)==0 &&
			   employee_getId(thisB, &auxIdB)==0)
			{
				if(auxIdA > auxIdB)
				{
					rtn=1;
				}
				if(auxIdA < auxIdB)
				{
					rtn=-1;
				}
			}
		}
	return rtn;
}

int employee_sortNombres(void* thisA, void* thisB){
	int rtn=0;
	char auxNombreA[150];
	char auxNombreB[150];

		if(thisA!=NULL && thisB!=NULL)
		{
			if(employee_getNombre(thisA, auxNombreA)==0 &&
			   employee_getNombre(thisB, auxNombreB)==0)
			{
				if(strcmp (auxNombreA , auxNombreB) > 0)
				{
					rtn=1;
				}
				if(strcmp (auxNombreA , auxNombreB) < 0)
				{
					rtn=-1;
				}
			}
		}
	return rtn;
}

int employee_sortHoras(void* thisA, void* thisB){
	int rtn=0;
	int auxHorasA;
	int auxHorasB;

		if(thisA!=NULL && thisB!=NULL)
		{
			if(employee_getHorasTrabajadas(thisA, &auxHorasA)==0 &&
			   employee_getHorasTrabajadas(thisB, &auxHorasB)==0)
			{
				if(auxHorasA > auxHorasB)
				{
					rtn=1;
				}
				if(auxHorasA < auxHorasB)
				{
					rtn=-1;
				}
			}
		}
	return rtn;
}

int employee_sortSueldo(void* thisA, void* thisB){
	int rtn=0;
	int auxSueldoA;
	int auxSueldoB;

		if(thisA!=NULL && thisB!=NULL)
		{
			if(employee_getSueldo(thisA, &auxSueldoA)==0 &&
			   employee_getSueldo(thisB, &auxSueldoB)==0)
			{
				if(auxSueldoA > auxSueldoB)
				{
					rtn=1;
				}
				if(auxSueldoA < auxSueldoB)
				{
					rtn=-1;
				}
			}
		}
	return rtn;
}
