/*
 * calculos.h
 * Prototipo de Funciones para calcular.
 * Eduard Brito Hernandez - Divisi?n 1-E
 *
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

/**
 * \brief: Suma dos numeros enteros y devuelve el resultado.
 * \param: Recibe dos enteros por valor.
 * \return: Retorna la suma de los numeros ingresados.
 *
 */
int sumar(int numero1, int numero2);

/**
 * \brief: Resta dos numeros enteros y devuelve el resultado.
 * \param: Recibe dos enteros por valor.
 * \return: Retorna la resta de los numeros ingresados.
 *
 */
int restar(int numero1, int numero2);

/**
 * \brief: Divide dos numeros enteros y devuelve el resultado.
 * \param: Recibe dos enteros por valor.
 * \return: Retorna un float con la division de los numeros ingresados.
 *
 */
float dividir(int numero1, int numero2);

/**
 * \brief: Multiplica dos numeros enteros y devuelve el resultado.
 * \param: Recibe dos enteros por valor.
 * \return: Retorna el producto de los numeros ingresados.
 *
 */
int multiplicar(int numero1, int numero2);

/**
 * \brief: Calcula el factorial de un numero entero y devuelve el resultado.
 * \param: Recibe un entero por valor.
 * \return: Retorna el factorial del numero ingresado.
 *
 */
int factorial(int numero);

#endif /* CALCULOS_H_ */
