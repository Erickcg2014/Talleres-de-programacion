/**********************************
FECHA: 30/01/2023
AUTOR: ERICK SANTIAGO CAMARGO GARCIA 

PROBLEMA:
SE TIENE UN GYM QUE REQUIERE UN SISTEMA INFORMATICO PARA CAPTURAR LOS DATOS DE SUS CLIENTES"

CARACTERISTICAS:
SE CREA UN STRUCT PARA HACER EL TIPO DE DATO QUE CAPTURE LOS DATOS 
SE PRESENTE QUE POR CADA DATO, SE IMPRIME LA PREGUNTA Y SE CAPTURE
**********************************/

#include <stdio.h>

struct gym{
	char nombre[30];
	int edad;
	int cc;
	float MC;
	char genero[30];
	int movil;
	int cant_hijos;
	char direccion[40];
};

int main(){
	/*se declara el tipo de dato gym*/
	struct gym persona;
	
		printf("........Bienvenido al sistema digital del gimnasio.......... \n");
	printf("\n Ingrese los siguientes datos para tenerlos en el sistema de informacion \n\n");
	
	printf("\n Ingrese su nombre \n");
	scanf("%s",&persona.nombre);
	
	printf("\n Ingrese su edad \n");
	scanf("%d",&persona.edad);
	
	printf("\n Ingrese su cedula de ciudadania \n");
	scanf("%d",&persona.cc);
	
	printf("\n Ingrese su masa corporal \n");
	scanf("%f",&persona.MC);
	
	printf("\n Ingrese su genero \n");
	scanf("%s",&persona.genero);
	
	printf("\n Ingrese su numero de telefono celular \n");
	scanf("%d",&persona.movil);
	
	printf("\n Ingrese cantidad de hijos \n");
	scanf("%d",&persona.cant_hijos);
	
	printf("\n Ingrese su direccion de vivienda \n");
	scanf("%s",&persona.direccion);


	printf("\n Se ha ingresado de forma satisfactoria a:\n");
	printf("%s",persona.nombre);
	
	
}
