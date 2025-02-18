#include <iostream>
#include "complex.hpp"

int main() {
    // Crear dos números complejos
    Complex c1(2.0,- 1.0);
    Complex c2(3.0, 2.0);
    std::cout << "Primer numero: ";
    c1.print(); 
    std::cout << std::endl;

    std::cout << "Segundo número: ";
    c2.print(); 
    std::cout << std::endl;
    //Enseña norma
    std::cout << "La norma del primer complejo es: " << c1.norm() << std::endl;
    std::cout << "La norma del segundo complejo es: " << c2.norm() << std::endl;
    //Conjugado
    Complex conjugado1 = c1.conjugate(); // Calcula el conjugado
    std::cout << "Conjugado del primer número: ";
    conjugado1.print();
    std::cout << std::endl;

    Complex conjugado2 = c2.conjugate(); // Calcula el conjugado
    std::cout << "Conjugado del segundo número: ";
    conjugado2.print(); 
    std::cout << std::endl;
    // Suma
    Complex Suma = c1 + c2;
    std::cout << "La suma de ambos complejos es: ";
    Suma.print(); 
    std::cout << std::endl;
    // Sustracción
    Complex Resta = c1 - c2;
    std::cout << "La resta es: ";
    Resta.print();
    std::cout << std::endl;
    // Multiplicación
    Complex multiplicacion = c1 * c2;
    std::cout << "El producto es: ";
    multiplicacion.print();
    std::cout << std::endl;
    // Dividir los dos números complejos
    Complex division = c1 / c2;
    std::cout << "La division es: ";
    division.print();
    std::cout << std::endl;

    return 0;
}
