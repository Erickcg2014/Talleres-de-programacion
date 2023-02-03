
/****************************************************************
Fecha: 1-feb-2023
Autor: Erick Camargo

Problema: Un gimnasio se propone a automatizar el proceso de registro. Se necesita
solicitar el numero de usuarios a registrar inicialmente. Se debe solicitar la mayor cantidad 
de datos posibles, para ser usados posteriormente. De ser necesario, se recomienda preguntar
datos adicionales sobre sus hijos (nombre, edad, entre otros, adicional). 
Se necesita que al final de la ejecución, se presente el nombre de los usuarios registrados satisfactoriamente. 

Solucion:
	* Se hara un TDA general para la captura de datos del usuarios 
	* Se hara un TDA aninado, para la captura de datos de los hijos 
	* Se presentara todos los anuncios posibles descriptivos
****************************************************************/

#include <stdio.h>
#include <iostream>

using namespace std;

//Se crea un TDA para la captura de los datos de cada usuario
struct gym_usuario{
	string nombre;
	int edad;
	long long cedula;
	long long movil;
	float masa_corporal;
	string genero;
	//Se anida un TDA para la captura de datos de los hijos
	struct gym_hijo{
		string nombre;
		int cantidad;
		int cedula;
	};
	gym_hijo hijo_usuario;
	
};

int main(){
	//variables globales
	int i,k,cantidad_usuarios;

	
	//Se da la bienvenida y presentacion
	cout<<"\n******************************************\n";
	cout<<"\n*************Bienvenido al Gym************\n";
	cout<<"\n******************************************\n\n";
	//Se solicita numero de usuarios a registrar inicialmente
	cout<<"¿Cuantos usuarios va a registrar?: ";
	cin>>cantidad_usuarios;
	cout<<"\n se van a aceptar:\n"<<cantidad_usuarios;	
	
	//Se crea un arreglo (vector) del TDA gym_usuario de tamaño cantidad_usuarios
	gym_usuario registro_persona[cantidad_usuarios];
	//Se crea un ciclo o bucle para capturar todos los datos de los usuarios a registrar
	for(i=0;i<cantidad_usuarios;i++){
		//se solicita cada datos y se almacena
		cout<<"\n Ingrese nombre:";
		cin>>registro_persona[i].nombre;
		cout<<"\n Ingrese edad:";
		cin>>registro_persona[i].edad;
		cout<<"\n Ingrese numero de cedula:";
		cin>>registro_persona[i].cedula;
		cout<<"\n Ingrese numero de telefono:";
		cin>>registro_persona[i].movil;
		cout<<"\n Ingrese masa corporal:";
		cin>>registro_persona[i].masa_corporal;
		cout<<"\n Ingrese genero:";
		cin>>registro_persona[i].genero;
		cout<<"\n Ingrese cantidad de hijos:";
		cin>>registro_persona[i].hijo_usuario.cantidad;
		//Se crea otro bucle para registrar los datos segun la cantidad de hijos 
			for(k=0;k<registro_persona[i].hijo_usuario.cantidad;k++){
			//Se solicita cada nombre del hijo
			cout<<"\n Ingrese nombre del hijo:";
			cin>>registro_persona[i].hijo_usuario.nombre;
			cout<<"\n Ingrese cedula del hijo:";
			cin>>registro_persona[i].hijo_usuario.cedula;	
			//Al salir del for, retornara al bucle principal
			}
		
	}
	//Se empieza a concluir el programa
	cout<<"\n******************************************\n";
	cout<<"\n Usuarios registrados satisfactoriamente:";
		for(i=0;i<cantidad_usuarios;i++){
		cout<<i+1<<":"<<registro_persona[i].nombre<<endl;
	}
	//Se da por finalizado el programa
	cout<<"\nFin de ejecucion!!!!"<<endl;
	
	return 0;
	



}
