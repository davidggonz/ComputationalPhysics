#include <iostream>
#include "tuple.hpp"

int main() {
    try {
        // Prueba del constructor por defecto
        Tuple t1;
        std::cout << "Tuple t1 (constructor por defecto):" << std::endl;
        t1.print();

        // Prueba del constructor personalizado
        Tuple t2(5);
        std::cout << "Tuple t2 (constructor personalizado):" << std::endl;
        t2.print();

        // Asignar valores a t2
        double values2[] = {1, 2, 3, 4, 5};
        t2.assignValues(values2, 5);
        std::cout << "Tuple t2 después de asignar valores:" << std::endl;
        t2.print();

        // Prueba del constructor copia
        Tuple t3 = t2;
        std::cout << "Tuple t3 (constructor copia):" << std::endl;
        t3.print();

        // Asignar nuevos valores a t3
        double values3[] = {2, 4, 6, 8, 10};
        t3.assignValues(values3, 5);
        std::cout << "Tuple t3 después de asignar nuevos valores:" << std::endl;
        t3.print();

        // Prueba del operador de asignación
        t1 = t3;
        std::cout << "Tuple t1 (operador de asignación):" << std::endl;
        t1.print();

        // Prueba de operadores aritméticos
        Tuple t4 = t2 + t3;
        std::cout << "Tuple t4 (t2 + t3):" << std::endl;
        t4.print();

        Tuple t5 = t3 - t2;
        std::cout << "Tuple t5 (t3 - t2):" << std::endl;
        t5.print();

        Tuple t6 = t2 * t3;
        std::cout << "Tuple t6 (t2 * t3):" << std::endl;
        t6.print();

        Tuple t7 = t3 / t2;
        std::cout << "Tuple t7 (t3 / t2):" << std::endl;
        t7.print();

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
