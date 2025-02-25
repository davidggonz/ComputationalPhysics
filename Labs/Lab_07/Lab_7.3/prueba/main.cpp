#include <iostream>
#include "complex.hpp"

int main() {
    double real1, imagin1, real2, imagin2;

    // Pedir al usuario que ingrese los valores del primer número complejo
    std::cout << "Ingrese la parte real del primer número complejo: ";
    std::cin >> real1;
    std::cout << "Ingrese la parte imaginaria del primer número complejo: ";
    std::cin >> imagin1;

    // Pedir al usuario que ingrese los valores del segundo número complejo
    std::cout << "Ingrese la parte real del segundo número complejo: ";
    std::cin >> real2;
    std::cout << "Ingrese la parte imaginaria del segundo número complejo: ";
    std::cin >> imagin2;

    // Crear los objetos Complex con los valores ingresados
    Complex a(real1, imagin1);
    Complex b(real2, imagin2);

    // Mostrar los números complejos ingresados
    std::cout << "\nNúmero complejo a: " << a.real << " + " << a.imagin << "j" << std::endl;
    std::cout << "Número complejo b: " << b.real << " + " << b.imagin << "j" << std::endl;

    // Calcular y mostrar la norma de a y b
    std::cout << "\nNorma de a: " << a.norm() << std::endl;
    std::cout << "Norma de b: " << b.norm() << std::endl;

    // Calcular y mostrar el conjugado de a y b
    std::cout << "\nConjugado de a: " << a.conjugate() << std::endl;
    std::cout << "Conjugado de b: " << b.conjugate() << std::endl;

    // Realizar y mostrar las operaciones básicas
    Complex sum = a + b;
    Complex diff = a - b;
    Complex prod = a * b;
    Complex quot = a / b;

    std::cout << "\nSuma de a y b: " << sum.real << " + " << sum.imagin << "j" << std::endl;
    std::cout << "Resta de a y b: " << diff.real << " + " << diff.imagin << "j" << std::endl;
    std::cout << "Multiplicación de a y b: " << prod.real << " + " << prod.imagin << "j" << std::endl;
    std::cout << "División de a y b: " << quot.real << " + " << quot.imagin << "j" << std::endl;

    return 0;
}
