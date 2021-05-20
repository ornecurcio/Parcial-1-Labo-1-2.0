/*
 * Contribuyente.h
 *
 *  Created on: 12 may. 2021
 *      Author: orne_
 */

#ifndef Contribuyente_H_
#define Contribuyente_H_


typedef struct
{
	int idContribuyente;
	char name[50];
	char apellido[50];
	char cuit[14];
	int isEmpty;
}eContribuyente;

/** \brief  inicializa en el campo isEmpty en 1, libre
* \param pArray el puntero al primer array
* \param cantidadDeArray int, a recorrer
* \return int Returo (-1) si Error (0) si todo Ok
*/
int inicializarContribuyente(eContribuyente pArray[], int cantidadDeArray);
/**
* \brief  busca en el campo isEmpty del array, un 1 para ingresar datos
* \param pArray el puntero al primer array
* \param cantidadDeArray int, a recorrer
* \return int Retorno (-1) si Error, retorna un int de posicion si todo Ok
*/
int buscaLibreContribuyente(eContribuyente pArray[], int cantidadDeArray);
/**
* \brief  evalua si existe al menos un contribuyente cargado a travez del campo isEmpty
* \param pArray el puntero al primer array
* \param cantidadDeArray int, a recorrer
* \return int Retorno (-1) si Error, retorna 0 si al menos hay un lugar del array ocupado.
*/
int hayContribuyente(eContribuyente pArray[], int cantidadDeArray);
/**
* \brief alta un contribuyente, llama a otras funciones que valida los datos de cada campo a cargar
* \param aContribuyente array donde se cargan los datos
* \param cantidadDeArray int, recorrer array
* \param contadorId int como puntero, donde se cargara el ID de manera autoincremental
* \return int Retorno (-1) si ERROR (0) SI TODO Ok
*/
int altaContribuyente(eContribuyente aContribuyente[], int cantidadDeArray, int* contadorId);
/**
* \brief imprime un contribuyente
* \param aEmpleado, recibe por valor de la estructura de un contribuyente
*/
void imprimir1Contribuyente(eContribuyente aContribuyente);
/**
* \brief lista todas los contribuyentes existentes
* \param aArray vector recaudacion
* \param cantidadDeArray int, longitud a recorrer
* \return int Retorno (-1) si ERROR (0) SI TODO Ok
*/
int imprimirContribuyentes(eContribuyente array[], int cantidadDeArray);
/**
* \brief busca ID de contribuyente pasado por valor, retorna la posicion del array donde se encuentra el contribuyente buscado
* \param aAuxiliar, vector contribuyente
* \param cantidadDeArray int, longitud a recorrer
* \param aID, valor del contribuyente a buscar
* \return i, int posicion del array donde se encuentra el contribuyente con id buscado
*/
int buscaContribuyenteXIdParametro(eContribuyente aAuxiliar[], int cantidadDeArray, int aID);
/**
* \brief busca contribuyente por ID solicitado en la funcion, retorna la posicion del array donde se encuentra el contribuyente buscado
* \param aAuxiliar, vector contribuyente
* \param cantidadDeArray int, longitud a recorrer
* \param aID, puntero que guarda el valor del ID buscado
* \return i, int posicion del array donde se encuentra el contribuyente con id buscado
*/
int buscaContribuyenteById(eContribuyente aAuxiliar[], int cantidadDeArray, int* aID);
/**
* \brief da de baja el contribuyente,  coloca en el campo isEmpty 1;
* \param aArray vector contribuyente
* \param posicion int, posicion del array a dar de baja
* \return int Retorno (-1) si ERROR (0) SI TODO Ok
*/
int bajaContribuyente(eContribuyente aAuxiliar[], int posicion);
/**
* \brief permite modificar un parametro del contribuyente, Apellido, Nombre o CUIT
* \param aArray vector contribuyente
* \param posicion int, posicion del array a modificar
* \return int Retorno (-1) si ERROR (0) SI TODO Ok
*/
int modifica1Contribuyente(eContribuyente aAuxiliar[], int posicion);
/**
* \brief al contribuyente en base a cuit ingresado
* \param aAuxiliar vector contribuyente
* \param cantidadDeArray int, longitud a recorrer
* \param aID puntero donde se guarda el id contribuyente encontrado
* \return i, posicion de array donde se encuentra el contribuyente encontrado
*/
int buscaConstribuyenteByCUIT(eContribuyente aAuxiliar[], int cantidadDeArray,  int* aID);

#endif /* Contribuyente_H_ */
