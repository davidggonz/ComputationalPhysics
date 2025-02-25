#include <stdio.h>

// Función que define la curva a integrar
double integrando(double variable) {
    return 4.0 / (1.0 + variable * variable);
}

// Función para calcular la integral
double integral(double x_inf, double x_sup, double (*func)(double), int steps) {
    double accum = 0.0;
    double h = (x_sup - x_inf) / steps;

    for (int i = 0; i < steps; i++) {
        double x = x_inf + h * (i + 0.5); // Punto medio del subintervalo
        accum += func(x);                // Sumar el valor de la función
    }

    return accum * h; // Multiplicar por el ancho del subintervalo
}

int main() {
    int steps = 100000; // Mayor cantidad de pasos para mayor precisión
    double pi = integral(0.0, 1.0, integrando, steps);

    printf("El valor aproximado de pi es: %.10f\n", pi);

    return 0;
}

