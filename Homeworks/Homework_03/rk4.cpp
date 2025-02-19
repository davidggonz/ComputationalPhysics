#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>  // Incluye la biblioteca para funciones matemáticas que usará para el sin(x) y cos(x)

//DEfinición de RK4
double rk4(double (*func)(double, double), double y0, double x0, double h) { //En este caso es y es la variable dependiente y x la independiente, esto incluso se puede confirmar por la condición incial
	//Definimos los k_i
	double k_1 = h * func(x0, y0);
	double k_2 = h * func(x0 + 0.5 * h, y0 + 0.5 * k_1);
	double k_3 = h * func(x0 + 0.5 * h, y0 + 0.5 * k_2);		
	double k_4 = h * func(x0 + h, y0 + k_3);
	return y0 + (k_1 + 2 * k_2 + 2 * k_3 + k_4) / 6; //Retorna la definición de RK4 en términos de lo que será evaluado una vez se llame la ecuación diferencial
}

//Definición de la función a integrar sobre x
double func_int(double x, double y){
	return sin(x + y) - cos(x - y); //Retorna la función sin(x + y) - cos(x + y)
}

//Void para generar el gráfico
void plot_graph(const std::vector<double>& y_vec, const std::vector<double>& x_vec) {
    FILE* gnuplot = popen("gnuplot -persistent", "w");
    if (gnuplot) {
        fprintf(gnuplot, "set title 'Gráfica de la integral'\n");
        fprintf(gnuplot, "set xlabel 'x'\n");
        fprintf(gnuplot, "set ylabel 'Y(x)'\n");
        fprintf(gnuplot, "plot '-' with linespoints title 'F(x,y)'\n");

        for (size_t i = 0; i < x_vec.size(); ++i) {
            fprintf(gnuplot, "%f %f\n", x_vec[i], y_vec[i]);
        }

        fprintf(gnuplot, "e\n");
        fclose(gnuplot);
    } else {
        std::cerr << "Error al abrir gnuplot." << std::endl; //Manejo de errores por aquello
    }
}

//Definición del main para la integración y correr el código
int main() {
	//Parámetros de integración
	double x0 = 0.0; //Definición de x inicial
	double y0 = 0.0; //Definición de y inicial
	double xf = 25.0; //Definición de x final
	double h = 0.025; //Definición del h 
	
	//Asignación de vectores para la graficación
	std::vector<double> x_vec;
	std::vector<double> y_vec;

	//Asignación de parámetros para a integración
	double x = x0;
	double y = y0;

	//Hacemos la integral avanzando con un while
	while (x < xf) {
        	double y = rk4(func_int, y, x, h); // Aplicar RK4
		y_vec.push_back(y); //Guarda el valor de y(x)
		x_vec.push_back(x); //Guarda el valor de x
        	x += h;                    // Avanzar en x
    	}
	//Hace gráfico
	plot_graph(y_vec, x_vec);

	return 0;
}
