#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"
#include "utn.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
void employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_findById(LinkedList* plist, int id);
void employee_ImprimirUno(Employee* this);

int employee_sortID(void* thisA, void* thisB);
int employee_sortNombres(void* thisA, void* thisB);
int employee_sortHoras(void* thisA, void* thisB);
int employee_sortSueldo(void* thisA, void* thisB);

#endif // employee_H_INCLUDED
