#include <iostream>
#include <omp.h>
#include <sys/time.h>
#include <fstream>
#include <vector>
#include <cstdio>
#include <cstdlib>


double seconds() //Se hace una función que calcule los segundos
{
 struct timeval tmp;
 double sec; //Se declara una función sec que almacenará el tiempo utilizado total en segundos
 gettimeofday( &tmp, (struct timezone *)0 ); //Función dada por el profesor para obtener el tiempo actual
                                             //donde &tmp es la dirección de la estructura tmp y se especifica
                                             //que no se necesita nada sobre la zona horaria.
 sec = tmp.tv_sec + ((double)tmp.tv_usec)/1000000.0; //La división convierte todo a segundos 
 return sec; //Se retorna
}


// Definición del integrando
double integrando(double x) {
    return 4.0 / (1.0 + x * x);
}
int num_procs;
// Función para la integración numérica utilizando suma de Riemann con punto medio.
double Int_Riemann(double(*func)(double), double lim_inf, double lim_sup, int steps) {
    double h = (lim_sup - lim_inf) / steps; // Definición de 'h'
    double Int = 0;
    #pragma omp parallel //Inicio de la paralelización
    {
    num_procs = omp_get_num_threads(); //Se obtienen los hilos utilizados
    #pragma omp for reduction(+: Int) //Proceso de reducción con el operador +
    for (int i = 0; i < steps; ++i) {
        Int += func(lim_inf + (i + 0.5) * h);
    }
    }
    return Int * h;
}

void plot_graph(const std::vector<int>& threads, const std::vector<double>& times) {
    FILE* gnuplot = popen("gnuplot -persistent", "w");
    if (gnuplot) {
        fprintf(gnuplot, "set title 'Escalabilidad'\n");
        fprintf(gnuplot, "set xlabel 'Num Threads'\n");
        fprintf(gnuplot, "set ylabel 'Execution time (s)'\n");
        fprintf(gnuplot, "plot '-' with linespoints title 'Time vs Threads'\n");

        for (size_t i = 0; i < threads.size(); ++i) {
            fprintf(gnuplot, "%d %f\n", threads[i], times[i]);
        }

        fprintf(gnuplot, "e\n"); 
        fclose(gnuplot);
    } else {
        std::cerr << "Error al abrir gnuplot." << std::endl; //Manejo de errores por aquello
    }
}


// Se corre con el main{}
int main() {
    int N = 100000; //Número de steps
    double x_inf = 0; //Limite inferior de la integral
    double x_sup = 1; //Limite superior de la integral  
    std::cout.precision(12); // 12 decimales de precisión
    std::vector<int> threads_list = {1, 2, 3, 4, 5, 6, 8}; // Número de hilos a probar
    std::vector<double> times;

    for (int num_threads : threads_list) {
        omp_set_num_threads(num_threads); // Configura el número de hilos
        double time_1 = seconds();
        Int_Riemann(integrando, x_inf, x_sup, N);
        double time_2 = seconds();
        double total_time = time_2 - time_1;
        times.push_back(total_time);   
        std::cout << "Threads: " << num_threads << " Time: " << total_time << " seconds" << std::endl;
    }

    plot_graph(threads_list, times);


    //double time_1 = seconds();
    //std::cout << Int_Riemann(integrando, x_inf, x_sup, N) << std::endl; //Se llama a la integral
    //double time_2 = seconds();
    //std::cout << "Time to complete loop: " << time_2 - time_1 << std::endl; //Printea el tiempo
    //std::cout << "Number of Threads: " << num_procs << std::endl; //Printea el número de hilos
    return 0;
}
    
 
