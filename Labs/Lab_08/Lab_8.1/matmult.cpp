#include <iostream>
#include <vector>
#include <omp.h>
#include <sys/time.h>

void print_mat(std::vector<double> &mat, int &rows, int &cols);

double seconds()
{
  struct timeval tmp;
  double sec;
  gettimeofday( &tmp, (struct timezone *)0 );
  sec = tmp.tv_sec + ((double)tmp.tv_usec)/1000000.0;
  
  return sec;
}

int main(int argc, char* argv[]){

  // Definamos la dimensión de las matrices mediante argumentos de la terminal
  if(argc != 7){
    std::cerr << "Usage: " << argv[0] << " --l [filas de A] --m [columnas de B] --n [columnas de A/filas de B]" << std::endl;
    exit(1);
  }
  // Ahora leemos las dimensiones
  int l, m, n;
  l = atoi(argv[2]);
  m = atoi(argv[4]);
  n = atoi(argv[6]);

  // Definamos nuestras matrices de entrada
  std::vector<double> A(l * n, 0.0); // Inicialización a 0.0
  std::vector<double> B(n * m, 0.0);
  std::vector<double> C(l * m, 0.0);

  // Inicialización de A
  for(int i = 0; i < l; ++i){
    for(int j = 0; j < n; ++j){
      A[(i * n) + j] = i;
    }
  }
  // Inicialización de B
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      B[(i * m) + j] = j;
    }
  }

  std::cout << "Matrix A = " << std::endl;
  print_mat(A, l, n);
  std::cout << "Matrix B = " << std::endl;
  print_mat(B, n, m);

  std::cout << "Calculando multiplicación..." << std::endl;
  // C ya se encuentra inicializada en 0!
  // Eso significa que podemos hacer la suma parcial en cada uno de sus elementos
  // Laboratorio: paralelizar la multiplicación de las matrices subdividiendo las *filas* de C
  int num_threads;
  double time_1 = seconds();
  #pragma omp parallel for //Calcular de forma automática la cantidad de trabajo utilizado
  for(int i = 0; i < l; ++i){
    num_threads = omp_get_num_threads();  
    for(int j = 0; j < m; ++j){
      for(int k = 0; k < n; ++k){
        C[(i * m) + j] += A[(i * n) + k] * B[(k * m) + j];
      }
    }
  }
  std::cout << "Resultado C = " << std::endl;
  print_mat(C, l, m);
  

  double time_2 = seconds();
  
  // Laboratorio: Cuente el número de hilos usando la API e imprima el resultado al final del programa
  std::cout << "# Num Threads: " << num_threads << std::endl;
  std::cout << "# Time: " << time_2 - time_1 << std::endl;

  return 0;
}

void print_mat(std::vector<double> &mat, int &rows, int &cols){
  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < cols; ++j){
      std::cout << mat[(i * cols) + j] << " ";
    }
    std::cout << std::endl;
  }
}

