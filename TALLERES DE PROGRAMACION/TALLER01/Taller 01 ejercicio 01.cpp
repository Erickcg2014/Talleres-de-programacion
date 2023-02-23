/*************************************************
 	*Autor: Erick Camargo
 	*Fecha:15-02-2022
 	*Tema:Taller 01
	*Problema #1: 
	1.- Crear un array con 10 elementos
	2.- Crear una funci�n para generar n�meros aleatorios entre 0 y 25
	3.- Llenar el array con 10 n�meros aleatorios
	4.- Crear un puntero
	5.- Imprimir el contenido del array usando el puntero
	6.- Imprimir las direcciones del contenido del array usando el puntero.	
	
****************************************************/

#include <iostream>
#include <fstream>
#include <conio.h>
#include <ctime>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

int main(){
	
	//Se declaran las variables
	int array[10],*puntero;
	int i;
	//Se utiliza una funcion generadora de numeros aleatorios

	puntero=array;
	
	cout<<"Este es nuestro arreglo de 10 elementos \n";
	srand(time(0));
	for(i=0;i<10;i++){
	//variable = limite_inferior + rand()% (limite_superior+1-limite inferior)
		array[i]=0+rand()%(26);
	//Se imprime el arreglo con puntero
		cout<<*puntero<<" -> "<<&array[i]<<endl;
		puntero++;
	}	
	
}

