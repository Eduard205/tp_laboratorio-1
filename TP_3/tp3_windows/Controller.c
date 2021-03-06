#include "Controller.h"
#include <stdio.h>
#include "Employee.h"
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int rtn = -1;
	char validacionSoN = 's';

		if (path != NULL && pArrayListEmployee != NULL)
		{
			if(ll_isEmpty (pArrayListEmployee) == 1)
			{
				FILE *pFile=fopen(path,"r");

				if(pFile != NULL && parser_EmployeeFromText(pFile, pArrayListEmployee)== 0)
				{
					printf("\nArchivo leido con ?xito");
					rtn = 0;
				}else{
						printf("\nNo se pudo leer el archivo");
						}

				fclose(pFile);

			}else{

				utn_getCharRespSoN(&validacionSoN, "\nYa hay datos cargados, desea guardarlos? (s/n): ","\n Error, ingrese nuevamente", 3);

				switch (validacionSoN)
				{
					case 'n':
						printf("\nSe han borrado los datos cargados.");
						ll_clear(pArrayListEmployee);
						FILE *pFile=fopen(path,"r");

						if(pFile != NULL && parser_EmployeeFromText(pFile, pArrayListEmployee)== 0 )
						{
							printf("\nArchivo nuevo leido con ?xito");
							fclose(pFile);
							rtn = 0;
						}
						break;

					case 's':
						if(controller_saveAsText("back.csv", pArrayListEmployee)== 0)
						{
							ll_clear(pArrayListEmployee);
							FILE *pFile=fopen(path,"r");

								if(pFile != NULL && parser_EmployeeFromText(pFile, pArrayListEmployee)== 0)
								{
									printf("\nArchivo nuevo leido con ?xito");
									fclose(pFile);
									rtn = 0;
								}
						}
						break;
				}
				}
		}
	return rtn;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int rtn= -1;
	char validacionSoN;

		if (path != NULL && pArrayListEmployee != NULL)
		{

			if(ll_isEmpty (pArrayListEmployee )== 1)
			{
				FILE *pFile=fopen(path,"rb");

				if(pFile != NULL && parser_EmployeeFromBinary(pFile, pArrayListEmployee)== 0)
				{
					printf("\nArchivo leido con ?xito");
					rtn = 0;

				}else{
						printf("\nNo se pudo leer el archivo");
						}

				fclose(pFile);

			}else{

				utn_getCharRespSoN(&validacionSoN, "\nHay datos cargados en el sistema, desea guardarlos? (s/n)","\n Error, ingrese nuevamente", 3);

				switch (validacionSoN)
				{
					case 'n':
						printf("\nSe han borrado los datos cargados");
						ll_clear(pArrayListEmployee);
						FILE *pFile=fopen(path,"rb");

						if(pFile != NULL && parser_EmployeeFromBinary(pFile, pArrayListEmployee)== 0)
						{
							printf("\nArchivo nuevo leido con ?xito");
							fclose(pFile);
							rtn = 0;
						}
					break;

					case 's':
						if (controller_saveAsBinary("back.bin",pArrayListEmployee)== 0)
						{
							ll_clear(pArrayListEmployee);
							FILE *pFile=fopen(path,"rb");

							if(pFile != NULL && parser_EmployeeFromBinary(pFile, pArrayListEmployee)== 0)
							{
								printf("\nArchivo nuevo leido con ?xito");
								fclose(pFile);
								rtn = 0;
							}
						}
					break;
				}
				}
		}
	return rtn;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int rtn = -1;
    Employee *auxEmpleado = NULL;
	char auxNombre[150];
	int auxHorasTrabajadas;
	int auxSueldo;
	int lenListaEmpleados;
	int i;
	int idMax=0;

    	if (pArrayListEmployee != NULL)
    	{

    		printf("\n---------------- Alta de un nuevo Empleado -------------\n");
    		if (pedirCadena(auxNombre, 150, 3, "Ingrese Nombre: ","Error, reingrese Nombre: ")== 1 &&
				pedirEntero(&auxHorasTrabajadas, 0, 200, 3, "Ingrese Horas Trabajadas: ","Error, reingrese Horas Trabajadas: ")== 1 &&
				pedirEntero(&auxSueldo, 1, 500000, 3, "Ingrese Sueldo: ", "Error, reingrese Sueldo: ")== 1)
    		{

    			if( ll_isEmpty(pArrayListEmployee) == 0)
    			{

    				lenListaEmpleados = ll_len(pArrayListEmployee);

					for(i=0; i<lenListaEmpleados ; i++)
					{
						auxEmpleado =ll_get(pArrayListEmployee, i);

						employee_getId(auxEmpleado, &idMax);

					}
    			 }
    					idMax++;

    				    auxEmpleado = employee_new();

    					if( employee_setId(auxEmpleado, idMax)== 0 &&
    						employee_setNombre(auxEmpleado, auxNombre)== 0 &&
							employee_setHorasTrabajadas(auxEmpleado, auxHorasTrabajadas)== 0 &&
							employee_setSueldo(auxEmpleado, auxSueldo)== 0)
    					{
    						ll_add(pArrayListEmployee, auxEmpleado);

							printf("\nEl Empleado cargado es: \n");
							employee_ImprimirUno(auxEmpleado);
							rtn=0;

    					}else{
    						printf("\nError al cargar el Empleado \n");
    						}
    		}
    	}
    return rtn;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int rtn = -1;
	Employee *auxEmpleado = NULL;
	char auxNombre[200];
	int auxHorasTrabajadas;
	int auxSueldo;
	int datoAMod;
	int idEmpleadoAMod;
	int lenEmpleados;
	int idMax;
	int i;
	int indexEmployee;

		if(ll_isEmpty(pArrayListEmployee)== 0 && pArrayListEmployee != NULL)
		{
			printf("\n--------------- Modificacion de un empleado ------------- \n");

			lenEmpleados = ll_len(pArrayListEmployee);

			for(i=0; i<lenEmpleados ; i++)
			{
				auxEmpleado = ll_get(pArrayListEmployee, i);
				employee_getId(auxEmpleado, &idMax);
			}

			if(pedirEntero(&idEmpleadoAMod, 0, idMax, 3, "\nIngrese el id del Empleado a modificar: ","\nError, ingrese un Id valido: ")== 1)
			{
				if(employee_findById(pArrayListEmployee, idEmpleadoAMod)!= -1)
				{

				indexEmployee = employee_findById(pArrayListEmployee, idEmpleadoAMod);

				auxEmpleado = ll_get(pArrayListEmployee, indexEmployee);

				printf("\nEmpleado encontrado");
				employee_ImprimirUno(auxEmpleado);

				}else{
					printf("\n\nID no encontrado");
					}


				do{
					pedirEntero(&datoAMod, 1, 4, 3, "\n INGRESE UNA OPCION \n1- Modificar Nombre. \n2- Modificar Horas Trabajadas. \n3- Modificar Salario. \n4- Volver al menu principal.\n","\n Error, ingrese nuevamente");

					switch (datoAMod)
					{
						case 1:
							if (pedirCadena(auxNombre, 200, 3, "\n Ingrese Nombre: ","\n Error, reingrese Nombre: ")== 1 &&
								employee_setNombre(auxEmpleado, auxNombre)== 0)
								{
									printf("\n DATOS MODIFICADOS------------------------------- \n");
									employee_ImprimirUno(auxEmpleado);
									rtn=0;
								}
						break;

						case 2:
							if (pedirEntero(&auxHorasTrabajadas, 0, 200, 3, "\n Ingrese las Horas Trabajadas: ","\n Error, reingrese Horas Trabajadas: ")== 1 &&
								employee_setHorasTrabajadas(auxEmpleado, auxHorasTrabajadas)== 0)
								{
									printf("\n DATOS MODIFICADOS------------------------------- \n");
									employee_ImprimirUno(auxEmpleado);
									rtn=0;
								}
						break;

						case 3:
							if (pedirEntero(&auxSueldo, 1, 500000, 3, "\n Ingrese el Sueldo: ","\n Error, reingrese Sueldo: ")== 1 &&
								employee_setSueldo(auxEmpleado, auxSueldo)== 0)
								{
									printf("\n DATOS MODIFICADOS--------------------------- \n");
									employee_ImprimirUno(auxEmpleado);
									rtn=0;
								}
						break;

						case 4:
						break;
					}

				}while(datoAMod != 4);
			}

		}else{
			printf("No hay empleados cargados");
			}

    return rtn;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int rtn = -1;
	Employee *auxEmpleado = NULL;
	char datoAValidar;
	int idEmpleadoAMod;
	int lenEmpleados;
	int idMax;
	int i;
	int indexEmployee;

			if(ll_isEmpty(pArrayListEmployee)== 0 && pArrayListEmployee != NULL)
			{
				printf("\n--------------- Baja de un empleado ------------- \n");

				lenEmpleados = ll_len(pArrayListEmployee);

				for(i=0; i<lenEmpleados ; i++)
				{
					auxEmpleado = ll_get(pArrayListEmployee, i);
					employee_getId(auxEmpleado, &idMax);
				}

				if(pedirEntero(&idEmpleadoAMod, 0, idMax, 3, "\nIngrese el id del Empleado a dar de baja: ","\nError, ingrese un Id valido: ")== 1)
				{
					if(employee_findById(pArrayListEmployee, idEmpleadoAMod)!= -1)
					{

					indexEmployee = employee_findById(pArrayListEmployee, idEmpleadoAMod);

					auxEmpleado = ll_get(pArrayListEmployee, indexEmployee);

					printf("\nEmpleado encontrado");
					employee_ImprimirUno(auxEmpleado);

					}else{
						printf("\n\nID no encontrado");
						}

					utn_getCharRespSoN(&datoAValidar,"\n?Esta seguro que desea dar de baja este empleado? (s/n): ","Error, ingrese 's' o 'n': ",3);

					switch(datoAValidar)
						{
							case 's':
									ll_remove(pArrayListEmployee, indexEmployee);
									printf("\n Se dio de baja al Empleado");
									rtn=0;
							break;

							case 'n':
									printf("\n Se cancelo la baja del Empleado");
									rtn=0;
							break;

						}
				}

			}else{
				printf("No hay empleados cargados");
				}

    return rtn;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int rtn=-1;
	Employee* pEaux;
	int i;
	int  auxId;
	char auxNombre[150];
	int auxHorasTrabajadas;
	int auxSueldo;

	int len_EmployeeAux = ll_len(pArrayListEmployee);

	if(pArrayListEmployee != NULL && len_EmployeeAux>0)
	{
		for(i=0; i < len_EmployeeAux; i++)
	    {
	        pEaux = ll_get(pArrayListEmployee,i);

	    	employee_getId(pEaux, &auxId);
	    	employee_getNombre(pEaux, auxNombre);
	    	employee_getHorasTrabajadas(pEaux, &auxHorasTrabajadas);
	    	employee_getSueldo(pEaux, &auxSueldo);

	        printf("ID: %d Nombre: %s sueldo: %d Horas_Trabajadas: %d\n",auxId, auxNombre,auxSueldo, auxHorasTrabajadas);
	        rtn=i;
	    }
	}
    return rtn;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int rtn = -1;
	int(*funcionTipoOrden)(void*,void*);
	int tipoDeSort;
	int lenEmpleados;

		lenEmpleados = ll_len(pArrayListEmployee);

		if (pArrayListEmployee != NULL && lenEmpleados > 0)
		{
			do{
			pedirEntero(&tipoDeSort, 1, 9, 3,"\n Ingrese una opcion del 1 al 9: "
						"\n1- Ordenar ID de forma ascendente "
						"\n2- Ordenar ID de forma descendente "
						"\n3- Ordenar Nombres de forma ascendente "
						"\n4- Ordenar Nombres de forma descendente "
						"\n5- Ordenar Horas de trabajo de forma ascendente "
						"\n6- Ordenar Horas de trabajo de forma descendente "
						"\n7- Ordenar Sueldo de forma ascendente "
						"\n8- Ordenar Sueldo de forma descendente "
						"\n9- Volver al menu principal        ", "\n Error, ingrese nuevamente");

						switch (tipoDeSort)
						{
							case 1:
							case 2:
								funcionTipoOrden = employee_sortID;
								break;
							case 3:
							case 4:
								funcionTipoOrden = employee_sortNombres;
								break;
							case 5:
							case 6:
								funcionTipoOrden = employee_sortHoras;
								break;
							case 7:
							case 8:
								funcionTipoOrden = employee_sortSueldo;
								break;
							case 9:
								break;
						}


				if(tipoDeSort % 2 != 0)
				{
					ll_sort(pArrayListEmployee, funcionTipoOrden, 1);

				}else{
					ll_sort(pArrayListEmployee, funcionTipoOrden, 0);
					}

				printf("\n     ** Lista Ordenada ** ");
				rtn = 0;

			}while(tipoDeSort != 9);

		}else{
			printf("No hay empleados cargados");
			}

    return rtn;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int rtn = -1;
	int auxId;
	char auxNombre[200];
	int auxHorasTrabajadas;
	int auxSueldo;

		if(ll_isEmpty(pArrayListEmployee) == 0)
		{
		FILE *pFile = fopen(path,"w");

			if (path != NULL && pArrayListEmployee != NULL && pFile != NULL)
			{

				fprintf( pFile,"id,    Nombre,    HorasTrabajadas,    Sueldo\n");

				for(int i = 0; i < ll_len(pArrayListEmployee); i++)
				{

					Employee  *auxEmployee = ll_get(pArrayListEmployee, i);

					if(employee_getId(auxEmployee, &auxId) == 0 &&
					employee_getNombre(auxEmployee, auxNombre) == 0 &&
					employee_getHorasTrabajadas(auxEmployee, &auxHorasTrabajadas) == 0 &&
					employee_getSueldo(auxEmployee, &auxSueldo) == 0 )
					{
					fprintf( pFile,"%d, %s, %d, %d\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
					}
				}

				fclose(pFile);
				printf("\nDatos guardados en %s", path);
				rtn = 0;
			}
		}else{
			printf("Error, No hay datos para guardar");

			}
	return rtn;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int rtn = -1;
	int cantEscrita;
	int lenEmployees;
	int i;

		if(ll_isEmpty(pArrayListEmployee)== 0)
		{
			if (path != NULL && pArrayListEmployee != NULL)
			{
				FILE *pFile=fopen(path,"wb");

				lenEmployees = ll_len(pArrayListEmployee);

				for(i = 0; i < lenEmployees; i++ )
				{

					Employee*  auxEmployee= ll_get(pArrayListEmployee, i);

					if(pFile != NULL)
					{
						cantEscrita = fwrite(auxEmployee, sizeof(Employee),1, pFile);
					}
				}

				if (cantEscrita < 1)
				{
					printf("\nError al escribir el archivo");

				}else{
					printf("\nDatos guardados en %s", path);
					rtn = 0;
					}

				fclose(pFile);
			}

		}else{
			printf("Error, No hay datos para guardar");
			}

    return rtn;
}

