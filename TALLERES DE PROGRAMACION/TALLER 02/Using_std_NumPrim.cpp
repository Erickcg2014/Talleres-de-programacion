#include <iostream>
#include <vector>

// Función para encontrar los números primos hasta un límite dado
std::vector<int> encontrarPrimos(int limite) {
    std::vector<int> primos;
    
    // Comprobamos si cada número hasta el límite es primo
    for (int num = 2; num <= limite; ++num) {
        bool esPrimo = true;
        
        // Comprobamos si el número es divisible por algún número menor que él
        for (int i = 2; i <= num / 2; ++i) {
            if (num % i == 0) {
                esPrimo = false;
                break;
            }
        }
        
        // Si el número es primo, lo agregamos al vector
        if (esPrimo) {
            primos.push_back(num);
        }
    }
    
    return primos;
}

int main() {
    int limite;
    std::cout << "Ingrese un límite: ";
    std::cin >> limite;
    
    std::vector<int> primos = encontrarPrimos(limite);
    
    std::cout << "Números primos hasta " << limite << ":\n";
    for (int primo : primos) {
        std::cout << primo << " ";
    }
    
    return 0;
}
