
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Recaudacion.h"
#include "UTN.h"

int inicializarRecaudacion(eRecaudacion pArray[], int cantidadDeArray)
{
	int retorno = -1;
	int i;
	if(pArray != NULL && cantidadDeArray>0)
	{
		for(i=0; i<cantidadDeArray; i++)
		{
			pArray[i].isEmpty=1;
		}
		retorno=0;
	}
	return retorno;
}

int buscaLibreRecaudacion(eRecaudacion pArray[], int cantidadDeArray)
{
	int retorno = -1;
	int i;

	if(pArray != NULL && cantidadDeArray>0)
	{
		for(i=0; i<cantidadDeArray; i++)
		{
			if(pArray[i].isEmpty==1)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int getDescripcionRecaudacion(eTipo aTipo[], int cantidadTipo, int buscar, char* descripcion)
{
	int i;
	int retorno = -1;

	for(i=0; i<cantidadTipo; i++)
	{
		if(aTipo[i].tipo==buscar && aTipo[i].isEmpty==0)
		{
			strcpy(descripcion, aTipo[i].descripcion);
			retorno=0;
		}
	}
	return retorno;
}

int altaRecaudacion(eRecaudacion aArray[], int cantidadDeArray, eContribuyente aContribuyente[], int cantidadContribuyente, int* contadorId)
{
	int retorno = -1;
	eRecaudacion aAuxiliar;
	int posicion;
	int auxI;
	char descripcion[20];

	if(aArray!=NULL && cantidadDeArray>0 && aContribuyente!=NULL && cantidadContribuyente>0)
	{
		posicion=buscaLibreRecaudacion(aArray, cantidadDeArray);
		if(posicion==-1)
		{
			printf("\nNo hay lugares libres");
		}
		else
		{
			if(buscaContribuyenteById(aContribuyente, cantidadContribuyente, &auxI)!=-1)
			{
				if((utn_getNumero(&aAuxiliar.tipo, "Ingrese Tipo 1.ARBA, 2.IIBB, 3.GANANCIAS", "Error,ingrese Tipo 1.ARBA, 2.IIBB, 3.GANANCIAS",1,3,2)==0)&&
				(utn_getNumero(&aAuxiliar.mes, "Ingrese MES", "Error,ingrese MES del 1 al 12",1,12,2)==0)&&
				(utn_getNumeroFlotante(&aAuxiliar.importe, "Ingrese importe","Error, ingrese de 100 a 1000", 100, 2000, 2)==0))
				{
					aAuxiliar.idContribuyente=auxI;
					aAuxiliar.idRecaudacion=0;
					printf("Estos son los datos, desea continuar:");
					if(aAuxiliar.tipo==1)
					{
						strcpy(descripcion,"ARBA");
					}
					if(aAuxiliar.tipo==2)
					{
						strcpy(descripcion,"IIBB");
					}
					if(aAuxiliar.tipo==3)
					{
						strcpy(descripcion,"GANANCIAS");
					}
					imprimir1Recaudacion(aAuxiliar, descripcion);
					if(utn_getCaracterSN()==0)
					{
					   (*contadorId)++;
					   aAuxiliar.idRecaudacion=*contadorId;
					   aAuxiliar.estado=2;
					   aAuxiliar.isEmpty=0;
					   aArray[posicion]=aAuxiliar;
					   imprimir1Recaudacion(aAuxiliar, descripcion);
					   retorno=0;
					}
				}
			}
		}
	}
		return retorno;
}

void imprimir1Recaudacion(eRecaudacion aRecaudacion, char* descripcion)
{
	printf("\n%-d   %-d      %-s        %-d    %-.2f        %-d ", aRecaudacion.idRecaudacion, aRecaudacion.tipo,
			descripcion,aRecaudacion.mes, aRecaudacion.importe, aRecaudacion.idContribuyente);
}

int imprimirRecaudacion(eRecaudacion array[], int cantidadDeArray, eTipo aTipo[], int cantidadTipo)
{
	int i;
	int retorno = -1;
	char descripcion[20];
	//CABECERA
	puts("\n\t LISTADO Recaudacion");
	printf("ID   TIPO   DESCRIPCION   MES   IMPORTE   ID Contribuyente");
	if (array != NULL && cantidadDeArray> 0 && aTipo!=NULL && cantidadTipo>0)
	{
		for (i = 0; i < cantidadDeArray; i++)
		{
			if (array[i].isEmpty == 1)
			{
				continue;
			}
			else
			{
				getDescripcionRecaudacion(aTipo, cantidadTipo, array[i].tipo, descripcion);
				imprimir1Recaudacion(array[i], descripcion);
				retorno=0;
			}
		}
	}
	return retorno;
}

int buscaIDRecaudacionRetIDCon(eRecaudacion aAuxiliar[], int cantidadDeArray, int contadorRecauda, int* posicion)
{
	int retorno = -1;
	int i;
	int auxI;


	if(aAuxiliar!=NULL && cantidadDeArray>0)
	{
		printf("Ingrese ID Recaudacion");
		scanf("%d", &auxI);
		for(i=0; i<cantidadDeArray; i++)
		{
			if(auxI==aAuxiliar[i].idRecaudacion && aAuxiliar[i].isEmpty==0)
			{
				*posicion=i;
				retorno=aAuxiliar[i].idContribuyente;
				break;
			}
			else
			{
				printf("Error, no existe ID");
			}
		}

	}
	return retorno;
}

int buscaRecaudacionByIdContribuyente(eRecaudacion aAuxiliar[], int cantidadDeArray, int* aID)
{
	int retorno = -1;
	int i;
	int auxInt;
	if(aAuxiliar!=NULL && cantidadDeArray>0)
	{
		printf("Ingrese ID de Contribuyente");
		scanf("%d", &auxInt);
		*aID=auxInt;
		for(i=0; i<cantidadDeArray; i++)
		{
			if(aAuxiliar[i].idContribuyente==auxInt && aAuxiliar[i].isEmpty==0)
			{
				retorno = i;
				break;
			}
			else
			{
				printf("El numero de ID %d no existe", auxInt);
				break;
			}
		}
	}
	return retorno;
}

int bajaRecaudacion(eRecaudacion aAuxiliar[], int posicion, eTipo aTipo[], int cantidadTipo)
{
	int retorno = -1;
	char descripcion[20];

	if(aAuxiliar!=NULL && posicion!=-1)
	{
		getDescripcionRecaudacion(aTipo, cantidadTipo, aAuxiliar[posicion].tipo, descripcion);
		imprimir1Recaudacion(aAuxiliar[posicion], descripcion);
		printf("\n¿Desea borrar esta recaudacion? ");
		if(utn_getCaracterSN()==0)
		{
			aAuxiliar[posicion].isEmpty=1;
			retorno = 0;
		}
	}
	return retorno;
}

int estadoRecaudacionRefinanciar(eRecaudacion aAuxiliar[], int posicion,eTipo aTipo[], int cantidadTipo)
{
	int retorno = -1;
	char descripcion[20];
	if(aAuxiliar!=NULL && posicion!=-1 && aTipo!=NULL && cantidadTipo>0)
	{
		getDescripcionRecaudacion(aTipo, cantidadTipo, aAuxiliar[posicion].tipo, descripcion);
		imprimir1Recaudacion(aAuxiliar[posicion], descripcion);
		printf("\n¿Desea refinanciar esta Recaudacion? ");
		if(utn_getCaracterSN()==0)
		{
			aAuxiliar[posicion].estado= REFINANCIAR;
			retorno = 0;
		}
	}
	return retorno;
}

int estadoRecaudacionSaldar(eRecaudacion aAuxiliar[], int posicion,eTipo aTipo[], int cantidadTipo)
{
	int retorno = -1;
	char descripcion[20];
	if(aAuxiliar!=NULL && posicion!=-1 && aTipo!=NULL && cantidadTipo>0)
	{
		getDescripcionRecaudacion(aTipo, cantidadTipo, aAuxiliar[posicion].tipo, descripcion);
		imprimir1Recaudacion(aAuxiliar[posicion], descripcion);
		printf("\n¿Desea saldar esta recaudacion? ");
		if(utn_getCaracterSN()==0)
		{
			aAuxiliar[posicion].estado= SALDADO;
			retorno = 0;
		}
	}
	return retorno;
}

int recaudacionxContribuyente(eRecaudacion array[], int cantidadDeArray, eTipo aTipo[], int cantidadTipo,int ID)
{
	int retorno = -1;
	int i;
	char descripcion[20];
	if(array!=NULL && cantidadDeArray>0)
	{
		for(i=0; i<cantidadDeArray; i++)
		{
			if(array[i].idContribuyente==ID)
			{
				getDescripcionRecaudacion(aTipo, cantidadTipo, array[i].tipo, descripcion);
				imprimir1Recaudacion(array[i],descripcion);
				retorno=0;
			}
		}
	}
	return retorno;
}

int bajaRecaudacionxContribuyente(eRecaudacion array[], int cantidadDeArray,int ID)
{
	int retorno = -1;
	int i;
	if(array!=NULL && cantidadDeArray>0)
		{
			for(i=0; i<cantidadDeArray; i++)
			{
				if(array[i].idContribuyente==ID)
				{
					array[i].isEmpty=1;
				}
			}
		}
	return retorno;
}

int listarContribuyentes(eRecaudacion aArray[], int cantidadDeArray, eContribuyente aContribuyente[], int cantidadContribuyente, eTipo aTipo[], int cantidadTipo)
{
	int retorno=-1;
	if(aArray!=NULL && aContribuyente!=NULL && aTipo!=NULL && cantidadDeArray>0 && cantidadContribuyente>0 && cantidadTipo>0)
	{
		printf("\nIDCont    APELLIDO         NOMBRE          CUIT");
		for(int i=0; i<cantidadContribuyente; i++)
		{
			if(aContribuyente[i].isEmpty==0)
			{

				imprimir1Contribuyente(aContribuyente[i]);

				recaudacionxContribuyente(aArray, cantidadDeArray, aTipo, cantidadTipo, aContribuyente[i].idContribuyente);
				retorno=0;
			}
		}
	}
	return retorno;
}

int imprimirRecaudacionSaldadas(eRecaudacion array[], int cantidadDeArray, eTipo aTipo[], int cantidadTipo,eContribuyente aContribuyente[], int cantidadContribuyente)
{
	int i;
	int retorno = -1;
	char descripcion[20];
	//CABECERA //%5s %10s %8s %8s %8s %10s %10s %10s\n"
	puts("\n\t> LISTADO Recaudacion SALDADAS");
	printf("IDRec      DESCRIPCION        MES          IMPORTE         IDCont      CUIL      APELLIDO NOMBRE");
	if (array != NULL && cantidadDeArray> 0 && aTipo!=NULL && cantidadTipo>0)
	{
		for (i = 0; i < cantidadDeArray; i++)
		{
			if (array[i].isEmpty == 1)
			{
				continue;
			}
			else
			{
				if(array[i].estado==SALDADO)
				{
					for(int j=0;j<cantidadContribuyente; j++)
					{
						if(aContribuyente[j].isEmpty==0 && array[i].idContribuyente==aContribuyente[j].idContribuyente)
						{
							getDescripcionRecaudacion(aTipo, cantidadTipo, array[i].tipo, descripcion);
							printf("\n %-d       %-s       %-d    %-.2f    %-d     %-s   %-s %-s", array[i].idRecaudacion, descripcion, array[i].mes, array[i].importe,
									array[i].idContribuyente, aContribuyente[j].cuit, aContribuyente[j].apellido, aContribuyente[j].name);
							retorno=0;
						}
					}
				}

			}
		}
	}
	return retorno;
}

int buscaRecaudacionMasAlta(eRecaudacion aAuxiliar[], int cantidadDeArray, eContribuyente aContribuyente[], int cantidadContribuyente, eTipo aTipo[], int cantidadTipo)
{
	int retorno=-1;
	int i, j;
	int flag=0;
	float mayor=0;
	if(aAuxiliar!=NULL && cantidadDeArray>0 && aContribuyente!=NULL && cantidadContribuyente>0 && aTipo!=NULL && cantidadTipo>0)
	{
		for(i=0; i<cantidadDeArray; i++)
		{
			if(aAuxiliar[i].isEmpty==1)
			{
				continue;
			}
			else
			{
				if(mayor<aAuxiliar[i].importe || flag==0)
				{
					mayor=aAuxiliar[i].importe;
					flag=1;
					retorno=0;
				}
			}
		}
		if(mayor!=0)
		{
			informes_RecaudacionMasAlta(aAuxiliar, cantidadDeArray, aContribuyente, cantidadContribuyente, aTipo, cantidadTipo, mayor);
		}
	}
	return retorno;
}

int buscaRecaudacionByCUIT(eRecaudacion aAuxiliar[], int cantidadDeArray, eContribuyente aContribuyente[], int cantidadContribuyente, eTipo aTipo[], int cantidadTipo)
{
	int retorno=-1;
	int auxI;
	int i;
	int j;
	char descripcion[30];
	char aCUIT[14];
	if(aAuxiliar!=NULL && cantidadDeArray>0 && aContribuyente!=NULL && cantidadContribuyente>0 && aTipo!=NULL && cantidadTipo>0)
	{
		if(buscaConstribuyenteByCUIT(aContribuyente, cantidadContribuyente, auxI)==0)
		{
			puts("\n\t> LISTADO Recaudacion");
			printf("%5s %10s %10s %8s %12s\n", "ID","ARCHIVO","CUIL","DIAS","ID Recaudacion");
			for(i=0; i<cantidadDeArray; i++)
			{
				if(aAuxiliar[i].idContribuyente==auxI && aAuxiliar[i].isEmpty==0)
				{
					getDescripcionRecaudacion(aTipo, cantidadTipo, aAuxiliar[i].tipo, descripcion);
					imprimir1Recaudacion(aAuxiliar[i], descripcion);
					retorno=0;
				}
			}
		}
	}
	return retorno;
}

int saldoPromedioRecaudaciones(eRecaudacion aAuxiliar[], int cantidadDeArray, eContribuyente aContribuyente[], int cantidadContribuyente )
{
	int retorno = -1;
	if(aAuxiliar!=NULL && cantidadDeArray>0 && aTipo!=NULL && cantidadTipo>0)
	{
		for(int i=0; i<cantidadDeArray; i++)
		{
			switch(aAuxiliar[i].tipo)
			{
				case 1:
					acumuladorARBA=+aAuxiliar[i].importe;
					contadorARBA++;
					break;
				case 2:
					acumuladorIIBB=+aAuxiliar[i].importe;
					contadorIIBB++;
					break;
				case 3:
					acumuladorGANAN=+aAuxiliar[i].importe;
					contadorGANAN++;
					break;
			}
		}
		if(contadorARBA>0)
		{
			promedioARBA=acumuladorARBA/contadorARBA;
			retorno=0;
		}
		if(contadorIIBB>0)
		{
			promedioIIBB=acumuladorARBA/contadorARBA;
			retorno=0;
		}
		if(contadorGANAN>0)
		{
			promedioGANAN=acumuladorARBA/contadorARBA;
			retorno=0;
		}
	}
}
