/*
 * Informe.h
 *
 *  Created on: 19 may. 2021
 *      Author: orne_
 */

#ifndef INFORMES_H_
#define INFORMES_H_

int informes_RecaudacionMasAlta(eRecaudacion aAuxiliar[], int cantidadDeArray, eContribuyente aContribuyente[],
									int cantidadContribuyente, eTipo aTipo[], int cantidadTipo, float importe);
int informes_RecaudacionSaldadasMayor1000(eRecaudacion array[], int cantidadDeArray, eTipo aTipo[],int cantidadTipo,
									 eContribuyente aContribuyente[], int cantidadContribuyente);
int informes_ContribuyentesXtipoRecaudaciones(eRecaudacion aAuxiliar[], int cantidadDeArray, eTipo aTipo[], int cantidadTipo,
		                             eContribuyente aContribuyente[], int cantidadContribuyente);
int informe_RecaudacionSaldadasFebrero(eRecaudacion array[], int cantidadDeArray,
									 eContribuyente aContribuyente[], int cantidadContribuyente);
#endif /* INFORMES_H_ */
