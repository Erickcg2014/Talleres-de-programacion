/**********************************************

	*Autor: Erick Camargo
	*Fecha:22/02/2023
	*Taller 02
	
	problema: Se desea hacer un aplicación que genere un conjunto de números aleatorios entre 0 y
	20. En caso que el usuario quiera, se debe presentar un histograma sobre la frecuencia
	de los números del conjunto de números aleatorios. La aplicación deberá presentar un
	menú, que identifique en dos partes: a) presentar la generación del conjunto de
	números aleatorios y b) presentar el histograma del conjunto de números aleatorios.
	Para la solución del problema se recomienda:
		• Se recomienda repasar funciones, vectores, arrays y estructuras.
		• Hacer dos funciones para cada parte del menú.
		• Crear una estructura que encapsule los datos del conjunto de números
		aleatorios (Tamaño del conjunto, Max valor del conjunto y el conjunto).
		• El conjunto de números aleatorios sea un array.
		• El tipo de datos de la función para generar el conjunto debería ser la
		estructura.
		
*********************************************/
#include <iostream>
#include <time.h>
#include <fstream>
#include <conio.h>
#include <cstdlib>

using namespace std;
//Funciones de usuario
void generarVectorAleatorio();
void generarHistograma();
void Menu();

//Se crea la estructura que capturara los resultados Max y N 

struct resultados{
		int max_valor;
		int size_array;
		int num_aux[];
}resultados1;

//Declaración de variables 
int opcion,aleatorio,i,j,dias,oper;

int main(){
	cout<<"******************************TALLER 02**********************************"<<endl;
	cout<<"\n Digite la cantidad de dias: \t";
	cin>>dias;
	resultados1.num_aux[dias];
	Menu();
}

void generarVectorAleatorio(){
	//Se crea una array con la cantidad de elementos
	resultados1.num_aux[dias];
	
	//Se generan numero aleatorios entre 0 y 20
	srand(time(0));
	for(i=0;i<dias;i++){
		resultados1.num_aux[i]=0 + rand()%(20);
	}
	
	//Se imprime el vector completo
	cout<<"El vector aleatorio generado es: ";
	for(i=0;i<dias;i++){
		cout<<resultados1.num_aux[i]<<"  ";
	}
	resultados1.max_valor = resultados1.num_aux[0];
	for(i=0;i<dias;i++){
		if(resultados1.num_aux[i]>resultados1.max_valor){
			resultados1.max_valor=resultados1.num_aux[i];
		};
	}
	cout<<"\n Maximo valor: "<<resultados1.max_valor<<endl;
	cout<<"Tamano: "<<dias<<endl;
}

void Menu(){
	do{
		

	cout<<endl<<"Ingrese una de las siguientes opciones:"<<endl;
	cout<<"		0) Crear vector aleatorio con numero del 1 al 20 de tamano n"<<endl;
	cout<<"		1) Generar matriz de histograma"<<endl;
	cout<<"		2) Salir del programa"<<endl<<endl;
	cout<<"------->   ";cin>>opcion;
	
		switch(opcion){
			case 0:
				generarVectorAleatorio();
				cout<<endl<<endl;
				oper=-1;break;
			case 1:
				generarHistograma();
				cout<<endl<<endl;
				oper=-1;break;
			case 2: 
				cout<<"Gracias por todo querido usuario :)";
				oper=0;break;
			
			default:
				cout<<"Ingrese opcion valida"<<endl;
		}
		
	}while (oper<0);
}

void generarHistograma(){

	cout<<"\n	index	valor 	histograma"<<endl;
	
	for(j=0;j<=dias;j++){
		cout<<" " <<"   \t"<<j<<" "<<"   \t"<<resultados1.num_aux[j]<<"\t";
		for(i=0;i<=dias;i++){
			if(resultados1.num_aux[i]==resultados1.num_aux[j]){
				cout<<"*";
			}else {
				continue;
			}
		}
		cout<<endl;
	}
	cout<<endl;
}

