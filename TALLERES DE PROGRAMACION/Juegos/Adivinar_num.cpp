/* Autor: Erick Camargo
  adivinar un numero
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

int generarNumeroSecreto(int min, int max) {
    srand(time(0));
    return min + rand() % (max - min + 1);
}

int main() {
    int min = 1;
    int max = 100;
    int numeroSecreto = generarNumeroSecreto(min, max);
    int intentos = 0;
    int intento;

    std::cout << "¡Bienvenido al juego de adivinar el número!" << std::endl;
    std::cout << "Estoy pensando en un número entre " << min << " y " << max << "." << std::endl;

    do {
        std::cout << "Introduce tu intento: ";
        std::cin >> intento;
        intentos++;

        if (intento < numeroSecreto) {
            std::cout << "Demasiado bajo. Intenta nuevamente." << std::endl;
        } else if (intento > numeroSecreto) {
            std::cout << "Demasiado alto. Intenta nuevamente." << std::endl;
        } else {
            std::cout << "¡Felicitaciones! Adivinaste el número en " << intentos << " intentos." << std::endl;
        }
    } while (intento != numeroSecreto);

    return 0;
}
