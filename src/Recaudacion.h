/*
 * Recaudacion.h
 *
 *  Created on: 12 may. 2021
 *      Author: orne_
 */

#ifndef CONTRIBUYENTE_H_
#define CONTRIBUYENTE_H_

#include "Contribuyente.h"

#define SALDADO 0
#define REFINANCIAR 1
#define ADEUDADO 2

typedef struct
{
	int tipo;
	char descripcion[50];
	int isEmpty;
}eTipo;

typedef struct
{
	int idRecaudacion;
	int idContribuyente;
	int tipo;
	int mes;
	float importe;
	int estado;
	int isEmpty;
}eRecaudacion;

/** \brief  inicializa en el campo isEmpty en 1, libre
* \param pArray el puntero al primer array
* \param cantidadDeArray int, a recorrer
* \return int Returo (-1) si Error (0) si todo Ok
*/
int inicializarRecaudacion(eRecaudacion pArray[], int cantidadDeArray);
/**
* \brief  busca en el campo isEmpty del array, un 1 para ingresar datos
* \param pArray el puntero al primer array
* \param cantidadDeArray int, a recorrer
* \return int Retorno (-1) si Error, retorna un int de posicion si todo Ok
*/
int buscaLibreRecaudacion(eRecaudacion pArray[], int cantidadDeArray);
/**
* \brief  busca la descripcion del tipo de recaudacion, segun el parametro numerico
* \param aTipo el puntero al primer array
* \param cantidadDeArray, tamanio a recorrer
* \param buscar, la posicion del array y campo con el parametro numerico de tipo
* \param descripcion, puntero donde se guarda la descripcion obtenida
* \return int Retorno (-1) si Error, retorna un int de posicion si todo Ok
*/
int getDescripcionRecaudacion(eTipo aTipo[], int cantidadDeArray, int buscar, char* descripcion);
/**
* \brief alta un recaudacion, llama a otras funciones que valida los datos de cada campo a cargar
* \param aArray vector recaudacion donde se cargan los datos
* \param cantidadDeArray int, longitud a recorrer
* \param aContribuyente array que se recorre para asociar una recaudacion con un contribuyente
* \param cantidadContribuyente, longitud array a recorrer
* \param contadorId int como puntero, donde se cargara el ID de manera autoincremental de recaudacion
* \return int Retorno (-1) si ERROR (0) SI TODO Ok
*/
int altaRecaudacion(eRecaudacion aArray[], int cantidadDeArray, eContribuyente aContribuyente[], int cantidadContribuyente, int* contadorId);
/**
* \brief imprime una recaudacion
* \param aRecaudacion, recibe por valor la estructura de un recaudacion
* \param descripcion, recibe por puntero la descripcion del tipo de recaudacion
*/
void imprimir1Recaudacion(eRecaudacion aRecaudacion, char* descripcion);
/**
* \brief lista todas las recaudaciones existentes
* \param aArray vector recaudacion
* \param cantidadDeArray int, longitud a recorrer
* \param aTipo array que se recorre para asociar una descripcion del tipo de recaudacion
* \param cantidadTipo, longitud array a recorrer
* \return int Retorno (-1) si ERROR (0) SI TODO Ok
*/
int imprimirRecaudacion(eRecaudacion array[], int cantidadDeArray,  eTipo aTipo[], int cantidadTipo);
/**
* \brief busca ID de recaudacion retorna por valor el ID del contribuyente de la recaudacion buscada y
* 			por puntero la posicion donde se encuentra la recaudacion buscada
* \param aArray vector recaudacion
* \param cantidadDeArray int, longitud a recorrer
* \param aTipo array que se recorre para asociar una descripcion del tipo de recaudacion
* \param cantidadTipo, longitud array a recorrer
* \return int Retorno el valor de ID contribuyente de la recaudacion buscada
*/
int buscaIDRecaudacionRetIDCon(eRecaudacion aAuxiliar[], int cantidadDeArray, int contadorRecauda, int* posicion);
/**
* \brief da de baja las recaudaciones asociadas al contribuyente que se esta dando de baja
* \param aArray vector recaudacion
* \param cantidadDeArray int, longitud a recorrer
* \param ID valor del contribueyente
* \return int Retorno (-1) si ERROR (0) SI TODO Ok
*/
int bajaRecaudacionxContribuyente(eRecaudacion array[], int cantidadDeArray,int ID);
/**
* \brief da de baja las recaudaciones,  coloca en el campo isEmpty 1;
* \param aArray vector recaudacion
* \param posicion int, posicion del array a dar de baja
* \param aTipo array del tipo de recaudacion
* \param cantidadTipo, longitud array a recorrer
* \return int Retorno (-1) si ERROR (0) SI TODO Ok
*/
int bajaRecaudacion(eRecaudacion aAuxiliar[], int posicion, eTipo aTipo[], int cantidadTipo);
/**
* \brief cambia el estado de recaudacion a refinanciado
* \param aArray vector recaudacion
* \param posicion int, posicion del array a refinanciar
* \param aTipo array del tipo de recaudacion
* \param cantidadTipo, longitud array a recorrer
* \return int Retorno (-1) si ERROR (0) SI TODO Ok
*/
int estadoRecaudacionRefinanciar(eRecaudacion aAuxiliar[], int posicion,eTipo aTipo[], int cantidadTipo);
/**
* \brief cambia el estado de recaudacion a saldada
* \param aArray vector recaudacion
* \param posicion int, posicion del array a saldar
* \param aTipo array del tipo de recaudacion
* \param cantidadTipo, longitud array a recorrer
* \return int Retorno (-1) si ERROR (0) SI TODO Ok
*/
int estadoRecaudacionSaldar(eRecaudacion aAuxiliar[], int posicion,eTipo aTipo[], int cantidadTipo);
/**
* \brief lista las recaudaciones vigentes asociadas al ID contribuyente que se pasa por valor
* \param aArray vector recaudacion
* \param cantidadDeArray int, longitud a recorrer
* \param aTipo array del tipo de recaudacion
* \param cantidadTipo, longitud array a recorrer
* \param ID valor del contribueyente
* \return int Retorno (-1) si ERROR (0) SI TODO Ok
*/
int recaudacionxContribuyente(eRecaudacion array[], int cantidadDeArray, eTipo aTipo[], int cantidadTipo,int ID);
/**
* \brief lista los contribuyentes vigentes con sus recaudaciones
* \param aArray vector recaudacion
* \param cantidadDeArray int, longitud a recorrer
* \param aContribuyente vector contribuyente
* \param cantidadContribuyente longitud del array a recorrer
* \param aTipo array del tipo de recaudacion
* \param cantidadTipo, longitud array a recorrer
* \return int Retorno (-1) si ERROR (0) SI TODO Ok
*/
int listarContribuyentes(eRecaudacion aArray[], int cantidadDeArray, eContribuyente aContribuyente[], int cantidadContribuyente, eTipo aTipo[], int cantidadTipo);
/**
* \brief lista las recaudaciones vigentes saldadas con los datos de su contribuyente
* \param array vector recaudacion
* \param cantidadDeArray int, longitud a recorrer
* \param aTipo array del tipo de recaudacion
* \param cantidadTipo, longitud array a recorrer
* \param aContribuyente vector contribuyente
* \param cantidadContribuyente longitud del array a recorrer
* \return int Retorno (-1) si ERROR (0) SI TODO Ok
*/
int imprimirRecaudacionSaldadas(eRecaudacion array[], int cantidadDeArray, eTipo aTipo[], int cantidadTipo,eContribuyente aContribuyente[], int cantidadContribuyente);
/**
* \brief lista las recaudaciones asociadas a un cuit
* \param array vector recaudacion
* \param cantidadDeArray int, longitud a recorrer
* \param aContribuyente vector contribuyente
* \param cantidadContribuyente longitud del array a recorrer
* \param aTipo array del tipo de recaudacion
* \param cantidadTipo, longitud array a recorrer
* \return int Retorno (-1) si ERROR (0) SI TODO Ok
*/
int buscaRecaudacionByCUIT(eRecaudacion aAuxiliar[], int cantidadDeArray, eContribuyente aContribuyente[], int cantidadContribuyente, eTipo aTipo[], int cantidadTipo);


#endif /* CONTRIBUYENTE_H_ */
