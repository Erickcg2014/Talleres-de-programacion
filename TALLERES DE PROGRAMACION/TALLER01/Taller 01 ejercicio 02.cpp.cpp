/*********************************************************+

*Autor: Erick Camargo
 	*Fecha:15-02-2022
 	*Tema:Taller 01
	*Problema #2: Se desea capturar los datos de los clientes para ser impreso en la factura. Se requiere
	crear una estructura de datos, que encapsule los datos de los usuarios. Se requiere que
	el uso de la estructura sea a través de punteros. Se requiere imprimir las facturas en
	un fichero de texto.
		Recomendaciones:
	1.- Hacer funciones por separado
	2.- Anunciar/Documentar acciones
	3.- Identificar su fichero fuente .cpp
	4.- Subir el fichero fuente a un repositorio
	
****************************************************/

#include <iostream>
#include <fstream>
#include <conio.h>
#include <cstdlib>

using namespace std;

	//Se cre estructura llamada datos_usuarios
struct datos_usuario{
	char nombre_usuario[50],apellido[50],genero[20];
	int edad;
	long long movil, cedula;
}datos_usuario, *puntero = &datos_usuario; //se crea el puntero con la estructura

void Datos();
void imprimir_datos();

int main(){
	
	cout<<"********************************TALLER 01*****************************************"<<endl;
	cout<<"*******************************EJERCICIO 02*****************************************"<<endl;
	
	Datos();
	imprimir_datos();
	
}

void Datos(){
		//Se anuncian los datos que pediremos
		cout<<"\n Ingrese nombre: \t";
		cin.getline(puntero->nombre_usuario,30,'\n');
		cout<<"\n Ingrese Apellido: \t";
		cin.getline(puntero->apellido,50,'\n');
		cout<<"\n Ingrese genero: \t";
		cin.getline(puntero->genero,20,'\n');
		cout<<"\n Ingrese edad:	  \t";
		cin>>(puntero->edad);
		cout<<"\n Ingrese cedula: \t";
		cin>>(puntero->cedula);
		cout<<"\n Ingrese movil:  \t ";
		cin>>(puntero->movil);	
}

void imprimir_datos(){
	
	//En esta funcion se crea un fichero para almacenar los datos
	//Se utiliza ofstream creando el objeto (archivo_escritura) y con el nombre del fichero fisico (datos_usuario.txt)
	
	ofstream archivo_escritura;
	archivo_escritura.open("datos_usuario.txt");
	//Se utiliza condicional sobre el fichero 
	if(archivo_escritura.is_open()){
		archivo_escritura<<"\n Su nombre es -> \t"<<puntero->nombre_usuario<<endl;
		archivo_escritura<<"\n Su apellido es -> \t"<<puntero->apellido<<endl;
		archivo_escritura<<"\n Su genero es -> \t"<<puntero->genero<<endl;	
		archivo_escritura<<"\n Su edad es -> \t"<<puntero->edad<<endl;
		archivo_escritura<<"\n Su cedula es -> \t"<<puntero->cedula<<endl;
		archivo_escritura<<"\n Su movil es -> \t"<<puntero->movil<<endl;	
	}	else {
		cout<<"No tiene permisos para escritura"<<endl;
	}
	archivo_escritura.close();	
}
