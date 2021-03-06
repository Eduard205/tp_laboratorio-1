#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int rtn = -1;
	//char buffer[4][130];
	char id[256];
	char nombre[256];
	char horas[256];
	char sueldo[256];

		Employee* pAuxEmpleado=NULL;

		if(pFile != NULL && pArrayListEmployee != NULL){

			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horas, sueldo);

		while(!feof(pFile) ){

			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre,horas, sueldo);
			pAuxEmpleado = employee_newParametros(id, nombre,horas, sueldo);

			if(pAuxEmpleado != NULL){
				ll_add(pArrayListEmployee,pAuxEmpleado); //Se agregan todos los empleados de la lista a la linkedlist
				rtn=0;
				printf("Agrego todos los empleados a la lista");
			}

		}

		}
    return rtn;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int rtn=-1;
	int rtnLeido;
	Employee* pAuxEmpleado=NULL;
	Employee auxEmpleado;


		if(pFile!=NULL && pArrayListEmployee!=NULL)
		{
			while(!feof(pFile))
			{
				rtnLeido = fread(&auxEmpleado,sizeof(Employee),1,pFile);
				pAuxEmpleado = employee_new();

				if (pAuxEmpleado != NULL)
				{
					if(rtnLeido== 1)
					{
						if((employee_setId(pAuxEmpleado, auxEmpleado.id)== 0) &&
						(employee_setNombre(pAuxEmpleado, auxEmpleado.nombre)== 0) &&
						(employee_setHorasTrabajadas(pAuxEmpleado, auxEmpleado.horasTrabajadas)== 0) &&
						(employee_setSueldo(pAuxEmpleado, auxEmpleado.sueldo)== 0))
						{
							ll_add(pArrayListEmployee, pAuxEmpleado);
							rtn = 0;
						}
					}
				}
			}
		}
    return rtn;
}
