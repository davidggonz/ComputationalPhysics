#include <iostream>
#include <complex>
#include <vector>
#include <omp.h> // Incluir la biblioteca de OpenMP

int mandelbrot(const std::complex<double> &c, const int &maxits) {
    std::complex<double> z = 0;
    int n = 0;
    while (abs(z) <= 2 && n < maxits) {
        z = z * z + c;
        ++n;
    }
    return n;
}

int main() {
    int width = 150;
    int height = 45;
    int max_iter = 1000;
    double minX = -2.0, maxX = 1.0;
    double minY = -1.0, maxY = 1.0;

    // Matriz para almacenar los resultados
    std::vector<std::vector<char>> output(height, std::vector<char>(width));

    // Rutina principal para generar el conjunto
    #pragma omp parallel for // Paralelización del bucle exterior
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            std::complex<double> c(minX + (maxX - minX) * x / width,
                                  minY + (maxY - minY) * y / height);
            int n = mandelbrot(c, max_iter);

            // Almacenar el resultado en la matriz
            if (n == max_iter) {
                output[y][x] = '#';
            } else {
                output[y][x] = '.';
            }
        }
    }

    // Imprimir la matriz en orden
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            std::cout << output[y][x];
        }
        std::cout << std::endl;
    }

    return 0;
}
