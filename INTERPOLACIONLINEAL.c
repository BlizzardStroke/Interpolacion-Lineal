#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int validarNum(char [], char[]);

int main(){
	
	int opc;
	float x,y,z;
	char entrada[20];
	
	printf("\t\t\t-----INTERPOLACION LINEAL-----\n");
	do
	{
		printf("\nIngrese log a calcular:\n");
	    scanf("%s", &entrada);
	} while( validarNum(entrada,"entero")!=0 );
	x = atoi(entrada); 
	
    do
    {
	    printf("\nIngrese primer valor a interpolar:\n");
	    scanf("%s", &entrada);
	} while( validarNum(entrada,"entero")!=0 );
	y = atoi(entrada); 
	
	do
    {
		printf("\nIngrese segundo valor a interpolar:\n");
	    scanf("%s", &entrada);
	} while(validarNum(entrada,"entero")!=0 );
	z = atoi(entrada); 
	
	if(z==y)
	{
		printf("\n\n Los valores a interpolar deben ser distintos ");
		return 0;
	}
	do
	{
		printf("\nTipo de logaritmo:\n1.-Logaritmo base 10\n2.-Logaritmo natural\n");
		scanf("%s", &entrada);
	} while(validarNum(entrada,"entero")!=0 );
	opc = atoi(entrada); 
	
		if(opc == 1){
		double logaritmo0 = log10(x);
		double logaritmo1 = log10(y);
		double logaritmo2 = log10(z);
		printf("\nLog(%.2f)=%f\nLog(%.2f)=%f\nLog(%.2f)=%f", x, log10(x), y, log10(y), z,  log10(z));
    	double f = logaritmo1 + ((logaritmo2-logaritmo1)/(z-y))*(x-y);
    	printf("\nResulatdo f=%f\n",f);
    	double e = ((logaritmo0-f)/logaritmo0)*100;
    	printf("Error: %f\n",e);
    	
	}else{
		double logaritmo0 = log(x);
		double logaritmo3 = log(y);
		double logaritmo4 = log(z);
		printf("\nLN(%d)=%f\nLN(%d)=%f\nLN(%d)=%f", x, log(x), y, log(y), z,  log(z));
		double f = logaritmo3 + ((logaritmo4-logaritmo3)/(z-y))*(x-y);
    	printf("Resulatdo f=%f\n",f);
    	double e = ((logaritmo0-f)/logaritmo0)*100;
    	printf("Error: %f\n",e);
    	
	}
	return 0;
}

int validarNum(char cadena[' '], char opcion[' ']){
	int longitud = strlen(cadena);
	int i; 
	
	if(strcmp(opcion,"entero") == 0)
		for(i = 0 ; i < longitud ; i++){
			if(isdigit(cadena[i]) == 0){
				printf("\n %c No es un valor valido. ",cadena[i]);
				return 1;
			}
		}
	if(strcmp(opcion,"flotante") == 0)
		for(i = 0 ; i < longitud ; i++){
			if(isdigit(cadena[i]) == 0 && cadena[i] != 46 && cadena[i] != 45){
				printf("\n %c No es un valor valido. ",cadena[i]);
				return 1;
			}
		}	
	return 0;
}

