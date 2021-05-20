#include <stdio.h>
#include <stdlib.h>
#include "Recaudacion.h"

int informes_RecaudacionMasAlta(eRecaudacion aAuxiliar[], int cantidadDeArray, eContribuyente aContribuyente[], int cantidadContribuyente, eTipo aTipo[], int cantidadTipo, float importe)
{
	int retorno=-1;
	int i, j;
	char descripcion[30];
	if(aAuxiliar!=NULL && cantidadDeArray>0 && aContribuyente!=NULL && cantidadContribuyente>0 && aTipo!=NULL && cantidadTipo>0)
	{
		printf("CONTRIBUYENTE----------RECAUDACION----------PRECIO");
		for(i=0; i<cantidadDeArray; i++)
		{
			if(aAuxiliar[i].isEmpty==0 && aAuxiliar[i].importe==importe)
			{
				for(j=0; j<cantidadContribuyente; j++)
				{
					if(aAuxiliar[i].idContribuyente==aContribuyente[j].idContribuyente)
					{
						getDescripcionRecaudacion(aTipo, cantidadTipo, aAuxiliar[i].tipo, descripcion);
						printf("\n%-d %-s \t %-s \t %-d \t %-s \t %-.2f",aContribuyente[j].idContribuyente,
								aContribuyente[j].apellido,aContribuyente[j].name, aAuxiliar[i].idRecaudacion,descripcion, importe);
						retorno=0;
					}
				}
			}
		}
	}
	return retorno;
}
int informes_RecaudacionSaldadasMayor1000(eRecaudacion array[], int cantidadDeArray, eTipo aTipo[], int cantidadTipo,eContribuyente aContribuyente[], int cantidadContribuyente)
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
				if(array[i].estado==SALDADO && array[i].importe>1000)
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
int informes_ContribuyentesXtipoRecaudaciones(eRecaudacion aAuxiliar[], int cantidadDeArray, eTipo aTipo[], int cantidadTipo, eContribuyente aContribuyente[], int cantidadContribuyente)
{
	int retorno=-1;
	int auxInt;
	if(aAuxiliar!=NULL && cantidadDeArray>0 && aTipo!=NULL && cantidadTipo>0 && aContribuyente!=NULL && cantidadContribuyente>0)
	{
		utn_getNumero(&auxInt, "Ingrese tipo de recaudacion 1.ARBA, 2.IIBB, 3.GANANCIAS, 4.Salir", "Error, opcion incorrecta", 1, 4, 2);
		for(int i=0; i<cantidadDeArray; i++)
		{
			switch(auxInt)
			{
				case 1:

					if(aAuxiliar[i].tipo==1 && aAuxiliar[i].isEmpty==0)
					{
						for(int j=0; j<cantidadContribuyente;  j++)
						{
							if((aAuxiliar[i].idContribuyente == aContribuyente[j].idContribuyente) && aContribuyente[j].isEmpty==0)
							{
								imprimir1Contribuyente(aContribuyente[j]);
								retorno=0;
							}
						}
					}
					break;
				case 2:
					if(aAuxiliar[i].tipo==2 && aAuxiliar[i].isEmpty==0)
					{
						for(int j=0; j<cantidadContribuyente;  j++)
						{
							if((aAuxiliar[i].idContribuyente == aContribuyente[j].idContribuyente) && aContribuyente[j].isEmpty==0)
							{
								imprimir1Contribuyente(aContribuyente[j]);
								retorno=0;
							}
						}
					}
					break;
				case 3:
					if(aAuxiliar[i].tipo==3 && aAuxiliar[i].isEmpty==0)
					{
						for(int j=0; j<cantidadContribuyente;  j++)
						{
							if((aAuxiliar[i].idContribuyente == aContribuyente[j].idContribuyente) && aContribuyente[j].isEmpty==0)
							{
								imprimir1Contribuyente(aContribuyente[j]);
								retorno=0;
							}
						}
					}
					break;
			}//fin de switch
		}
	}
	return retorno;
}
int informe_RecaudacionSaldadasFebrero(eRecaudacion array[], int cantidadDeArray, eContribuyente aContribuyente[], int cantidadContribuyente)
{
	int i;
	int retorno = -1;
	puts("\n\t> LISTADO Recaudacion SALDADAS FEBRERO");
	printf("CUIL      APELLIDO NOMBRE");
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
				if(array[i].estado==SALDADO && array[i].mes==2)
				{
					for(int j=0;j<cantidadContribuyente; j++)
					{
						if(aContribuyente[j].isEmpty==0 && array[i].idContribuyente==aContribuyente[j].idContribuyente)
						{
							printf("\n%-14s		%-12s	%-12s", aContribuyente[j].cuit, aContribuyente[j].apellido, aContribuyente[j].name);
							retorno=0;
						}
					}
				}

			}
		}
	}
	return retorno;
}


