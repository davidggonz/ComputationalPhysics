#include <iostream>
#include <omp.h>
#include <sys/time.h>
#include <fstream>

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
// Se corre con el main{}
int main() {
    int N = 100000; //Número de steps
    double x_inf = 0; //Limite inferior de la integral
    double x_sup = 1; //Limite superior de la integral	
    std::cout.precision(12); // 12 decimales de precisión
    

    //Prueba
    // Archivo para guardar los datos
    std::ofstream archivo("escalabilidad.dat");

    // Probar con diferentes números de hilos
    for (int threads = 1; threads <= omp_get_max_threads(); ++threads) {
        omp_set_num_threads(threads); // Establecer el número de hilos
	std::cout << "FOR PARA " << threads << "hilos" << std::endl;
        double time_1 = seconds();
        std::cout << Int_Riemann(integrando, x_inf, x_sup, N) << std::endl;
        double time_2 = seconds();

        double tiempo_ejecucion = time_2 - time_1;

        // Guardar los datos en el archivo
        archivo << threads << " " << tiempo_ejecucion << std::endl;

        std::cout << "Threads: " << threads << " Time: " << tiempo_ejecucion << " seconds" << std::endl;
    }

    // Cerrar el archivo
    archivo.close();
    //Termino prueba

    double time_1 = seconds(); 
    std::cout << Int_Riemann(integrando, x_inf, x_sup, N) << std::endl; //Se llama a la integral
    double time_2 = seconds();
    std::cout << "Time to complete loop: " << time_2 - time_1 << std::endl; //Printea el tiempo
    std::cout << "Number of Threads: " << num_procs << std::endl; //Printea el número de hilos
    return 0;
}
