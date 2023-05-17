/***************
AUTORES:
  - FABIO ANDRES TRIANA RODRIGUEZ
  - DANIEL FRANCISCO OSORIO ROJAS
  - ERICK SANTIAGO CAMARGO
TEMA: PROYECTO DE AULA DE CLASES
MATERIA: PROGRAMACION AVANZADA


Empresa Minosaurios Tech, solicita registro de sus empleados.

La estructura de datos del empleado:
- Código numérico
- Nombres
- Apellidos
- Celular

FUNCIONES:
- Registrar empleados: se debe almacenar en un fichero binario "Empleados.bin"
- Agregar nuevos empleados: se verifica que el empleado no este, la informacion
se adiciona al final del fichero
- Mostrar los empleados registrados: Se imprime en la pantalla los empleados en
orden alfabetico.
- Cambiar el número de celular de un empleado:con el codigo del empleado, si
existe, se modifica.
- Despedir a un empleado: con el codigo, si existe,se elimina del archivo
binario. se genera una carta de despido.txt
- Mostrar empleados que han sido despedidos: se presenta un vector con los
empleados despedidos
*************/

#include <iostream> //Se incluye la libreria iostream
#include <fstream> //Se incluye la libreria fstream
#include <vector> //Se incluye la libreria vector
#include <string> //Se incluye la libreria string
#include <algorithm> //Se incluye la libreria algorithm

using namespace std; //Para el uso de nombres con std

// Estructura para almacenar información de un empleado
struct Empleado { //Se abre la estructura
    string nombre; //Se crea variable para guardar el nombre de los empleados
    string apellidos; //Se crea variable para guardar los apellidos de los empleados
    int codigo; //Se crea variable para guardar el codigo de los empleados
    string celular; //Se crea variable para guardar el celular de los empleados
    bool despedido; //Se crea variable para guardar si un empleado esta despedido
}; //Se cierra la estructura

int menu(){ // Se abre la funcion menu para mostrar las cosas que se pueden hacer con el programa
  cout<<" MENU: "<<endl; //Se imprime un titulo para imprimir el menu
  cout<<"     - 1. Registrar empleados"<<endl; //Se imprime la opcion de Registrar empleados
  cout<<"     - 2. Agregar nuevos empleados."<<endl; //Se imprime la opcion de Agregar nuevos empleados
  cout<<"     - 3. Mostrar los empleados registrados"<<endl; //Se imprime la opcion de Mostrar los empleados registrados
  cout<<"     - 4. Cambiar el número de celular de un empleado"<<endl; //Se imprime la opcion de Cambiar el número de celular de un empleado
  cout<<"     - 5. Despedir a un empleado"<<endl; //Se imprime la opcion de Despedir a un empleado
  cout<<"     - 6. Mostrar empleados que han sido despedidos"<<endl<<endl; //Se imprime la opcion de Mostrar empleados que han sido despedidos
  cout<<" Por favor ingrese unicamente el numero de la opcion que quiere realizar: "; //Se imprime para que el usuario sepa como usar el menu
  int op; //Se crea op para capturar la respuesta del usuario
  cin>>op; //Se guarda la respuesta del usuario
  cout<<endl;
  return op; //Se devuelve el valor de op
  } //Se cierra la funcion 


// Función para registrar un nuevo empleado
void registrar_nuevo_empleado(vector<Empleado>& empleados, ofstream& file) {
    Empleado nuevoEmpleado;// se crea el tipo struct empleado
    cout << "Ingrese los nombres del nuevo empleado: ";
    cin >> nuevoEmpleado.nombre;
    cout << "Ingrese los apellidos del nuevo empleado: ";
    cin >> nuevoEmpleado.apellidos;
    cout << "Ingrese el codigo del nuevo empleado: ";
    cin >> nuevoEmpleado.codigo;
    cout << "Ingrese el número de celular del nuevo empleado: ";
    cin >> nuevoEmpleado.celular;
    nuevoEmpleado.despedido = false;//// se pone en falso ya que es nuevo y no puede estar despedido
    empleados.push_back(nuevoEmpleado);// se guarda el nuevo empleado al final del vector con la funcion pushback
  // Guarda el vector de empleados actualizado en el archivo binario
    file.seekp(0);//// ubica el puntero de escritura al principio del archivo para sobreescribir completamente
    file.write(reinterpret_cast<const char*>(empleados.data()), empleados.size() * sizeof(Empleado));// convierte el puntero al inicio del vector de empleados en un puntero a char
  // se actualiza el vector con el nuevo empleado en el archivo binario
  // se utiliza la funcion empleados.data para obtener el puntero al inicio de
  // la funcion empleados
  // se utiliza empleados.size() * sizeof(Empleado) para calcular el número de
  // bytes que deben escribirse en el archivo. empleados.size() devuelve el
  // número de elementos en el vector de empleados sizeof(Empleado) devuelve el
  // tamaño en bytes de un objeto de tipo Empleado.
    cout << "Empleados registrado con éxito." << endl<<endl;//mensaje de exito
}

bool comparar_por_apellidos(const Empleado& a, const Empleado& b) {
    return a.apellidos < b.apellidos;
}

void mostrar_todo(const vector<Empleado>& empleados) {
    vector<Empleado> copia = empleados; // hacemos una copia del vector de empleados para no modificarlo directamente
    sort(copia.begin(), copia.end(), comparar_por_apellidos); // ordenamos la copia de los empleados según los apellidos

    cout << "Lista de empleados (ordenados por apellidos):" << endl;
    for (const auto& emp : copia) {
        cout << "Nombres: " << emp.nombre << endl;
        cout << "Apellidos: " << emp.apellidos << endl;
        cout << "Codigo: " << emp.codigo << endl;
        cout << "Número de celular: " << emp.celular << endl;
        cout << endl;
    }
}


// Función para cambiar el número de celular de un empleado
void cambiar_celular(vector<Empleado>& empleados, ofstream& empleadoArchivo) {// se toma un vector de Empleados y un objeto ofstream como argumentos
    int empCodigo;
    cout << "Ingrese el codigo del empleado cuyo número de celular desea cambiar: ";// solicita al usuario que ingrese el código del empleado cuyo número de celular desea cambiar
    cin >> empCodigo;
    for (auto& emp : empleados) {// se itera sobre cada elemento del vector de empleados
        if (emp.codigo == empCodigo) {// si el codigo digitado por el usuario esta entonces se pasa a pedir el numero de celular
            cout << "Ingrese el nuevo número de celular para " << emp.nombre << ": ";
            cin >> emp.celular;
            // Guarda el vector de empleados actualizado en el archivo binario
            empleadoArchivo.seekp(0);// se establece la posición de escritura al comienzo del archivo
            empleadoArchivo.write(reinterpret_cast<const char*>(empleados.data()), empleados.size() * sizeof(Empleado));// se escriben los datos actualizados del vector de empleados en el archivo binario
            cout << "Número de celular actualizado." << endl;// mensaje de exito al actualizar el numero de celular
            return;
        }
    }
    cout << "No se encontró ningún empleado con ese codigo." << endl;// Si ningún empleado tiene el código ingresado por el usuario, la función imprime un mensaje de error
}

//Se crea la función para despedir a un empleado con referencia al vector de empleados actual; referencia al vector de empleados despedidos; y referencia al objeto de flujo de salida de archivo binario que contiene los datos de los empleados
void despedir_empleado(vector<Empleado>& empleados, vector<Empleado>& empleados_despedidos, ofstream& empleadoArchivo) {
    int cod; //Se crea una variable para almacenar el código del empleado que se desea despedir.
    cout << "Ingrese el codigo del empleado que desea despedir: "; //Se pide por consola al usuario que ingrese el codigo del empleado que quiere despedir
    cin >> cod; //Se guarda el codigo que ingreso el usuario
    auto it = std::find_if(empleados.begin(), empleados.end(), [=](const Empleado& emp) { return emp.codigo == cod; }); //Se utiliza la función "find_if" de C++ para buscar en el vector empleados el primer elemento cuyo codigo sea igual al valor ingresado por el usuario. La búsqueda se realiza utilizando una función lambda que compara el codigo del empleado con cod. Si se encuentra un empleado con el código ingresado, se devuelve un iterador que apunta a ese empleado; de lo contrario, se devuelve un iterador que apunta al final del vector
    if (it != empleados.end()) { //Si se encuentra un empleado con el código ingresado, se ejecuta el if
        it->despedido = true; //Se actualiza el valor del miembro despedido del objeto Empleado apuntado por el iterador it a true, lo que significa que el empleado ha sido despedido
        empleados_despedidos.push_back(*it); //Se agrega el objeto Empleado apuntado por el iterador it al final del vector empleados_despedidos
        empleados.erase(it); //Se elimina el objeto Empleado apuntado por el iterador it del vector empleados, lo que implica que el empleado ha sido despedido y ya no forma parte de la lista de empleados activos
        empleadoArchivo.seekp(0); //Se utiliza la función seekp del objeto empleadoArchivo para mover el puntero de escritura al principio del archivo binario.
        empleadoArchivo.write(reinterpret_cast<const char*>(empleados.data()), empleados.size() * sizeof(Empleado)); //Se utiliza la función write del objeto empleadoArchivo para escribir en el archivo binario los datos del vector empleados actualizado, interpretados como una secuencia de bytes. Se escribe un número de bytes igual a la longitud del vector empleados multiplicada por el tamaño en bytes de cada objeto Empleado
        
        //Generar carta de despido en un archivo txt
        ofstream carta("carta_despido.txt");
        if(carta.is_open()) {
            carta << "Estimado/a " << it->nombre << " " << it->apellidos << ", Nos dirigimos respetuosamente a usted solicitando que entre el día de hoy y mañana haga entrega de su puesto y herramientas entregadas al inicio de sus labores con la empresa MINOSAURIOS TECH." <<endl;
          carta<<"De igual manera, Agradecemos las labores realizadas con nosotros, te deseamos muchos éxitos en tu futuro."<<endl;
          carta<<"ATT: Director de Minosaurios Tech"<<endl<<"Director de la empresa" << endl;
  
            carta << "Su codigo de empleado es: " << it->codigo << endl;
            carta.close();
            cout << "Carta de despido generada en el archivo 'carta_despido.txt'." << endl;
        } else {
            cout << "No se pudo generar la carta de despido." << endl;
        }
        
        cout << "Empleado despedido." << endl; //Se imprime Empleado despedido, indicando que se completo el proceso
    } //Se cierra el for
    else { //Se abre un else por si no se encuentra el codigo de ese empleado
        cout << "No se encontró ningún empleado con ese codigo." << endl;
      }
  }

//Se crea la función para mostrar la lista de empleados despedidos
void mostrarDespedidos(const vector<Empleado>& despedidos) {
    cout << "Empleados despedidos:\n"; //Se hace un titulo para mostar la lista de empleados despedidos
    for (const Empleado& empleado : despedidos) { //Se hace un for para recorrer la lista de todos los empleados despedidos
        //Se imprimen los datos de los empleados despedidos 
        cout << empleado.nombre << ", " << empleado.apellidos << ", " << empleado.codigo << ", " << empleado.celular; 
    } //Se cierra el for
}//Se cierra la funcion

ofstream crearArchivoBinarioVacio(const char* nombreArchivo) { //Se crea la función para crearArchivoBinarioVacio con un argumento de tipo "const char*", que será el nombre del archivo que se creará.
   
ofstream archivo(nombreArchivo, ios::binary); //Se crea un objeto de tipo ofstream y se le pasa como argumentos el nombre del archivo y el modo en el que se abrirá

  // Se verifica si el archivo se ha abierto correctamente
  if (!archivo) {
    std::cerr << "No se pudo abrir el archivo" << std::endl; //Se escribe en consola que no se pudo abrir el archivo
  }

  //Se retorna el objeto ofstream para que pueda ser utilizado en otras funciones
  return archivo;
}


int main() { //Se crea y se abre la funcion main
  ofstream archivo = crearArchivoBinarioVacio("Empleados.bin"); //Se crea el archivo binario con su respectivo nombre
  vector<Empleado> vector_registro; //Se crea vector para guardar los datos de los empleados
  vector<Empleado> vector_despedidos; //Se crea vector para guardar a los empleados despedidos
  cout<<"********************* MINOSAURIOS TECH *********************"<<endl; //Se le pone titulos que van a salir en la consola
  cout<<"************************ Bienvenido ************************"<<endl<<endl; //Se le pone titulos que van a salir en la consola
  
//Se crea variable para respuesta al do while
int op_exit;
int cant; // para guardar la cantidad de empleados en el case 1
//Se hace un do while para repetir el menu  
  do{
    switch (menu()){ //Se hace el switch tomando la opción que se marque en la funcion menu
      case 1:
      cout<<"¿Cuantos empleados va a registrar? ";
      cin>> cant;
      cout<<endl;
       for (int i = 0; i < cant; i++) {
        cout << "----EMPLEADO:" << i + 1 << "----" << endl;
        registrar_nuevo_empleado(vector_registro, archivo);
      }
      break;

      case 2:
      //Se llama a la funcion nuevo_empleado
      registrar_nuevo_empleado(vector_registro, archivo); 
      break;
      
      case 3:
      //Se llama a la funcion mostrar_todo_registros
      mostrar_todo(vector_registro);
      break;
      
      case 4:
      //Se llama a la funcion cambiar_celular
      cambiar_celular(vector_registro, archivo);
      break;
      
      case 5:
      //Se llama a la funcion despedir_empleado
      despedir_empleado(vector_registro,vector_despedidos,archivo);
      break;
      
      case 6:
      //Se llama a la funcion mostrar_despedidos
      mostrarDespedidos(vector_despedidos);
      break;
       
	    //Se hace el default del switch
      default: cout << "Usted ha ingresado una opción incorrecta"<<endl;
  }
    //Se pregunta si quiere continuar
      cout<<"Si desea continuar marque 1: ";
      //Se guarda el valor de la respuesta
      cin>>op_exit;
      cout<<endl;
    }
  //Se compara para ver si cumple la condicion
  while(op_exit==1);
} //Se cierra la funcion main