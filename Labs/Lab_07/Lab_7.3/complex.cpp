#include <iostream>
#include <cmath>

//Se incluye el archivo por declaración
#include "complex.hpp"

Complex::Complex(const Complex &obj){ //Constructor copia
  	std::cout << "Copy constructor invoked!" << std::endl;
  	real = obj.real;
  	imagin = obj.imagin;
}

Complex &Complex::operator=(const Complex &obj){ //Operador de asignación
  	std::cout << "Assignment operator invoked!" << std::endl;
  	real = obj.real;
 	imagin = obj.imagin;
  	return *this
}

double Complex::norm(){ //Se crea la función para sacar la norma
 	double nor = real*real + imagin*imagin;
  	return std::sqrt(nor);
}

double Complex::conjugate(){ //Se crea la función para sacar el conjugado
 	return real - imagin;
}

Complex &Complex::operator+(const Complex &obj){ //Operador suma
 	temp = Complex();
  	temp.real = real + obj.real;
  	temp.imagin = imagin + obj.imagin;
  	return temp
}

Complex &Complex::operator-(const Complex &obj){ //Operador sustracción
  	temp = Complex();
  	temp.real = real - obj.real;
  	temp.imagin = imagin - obj.imagin;
  	return temp
}

Complex &Complex::operator*(const Complex &obj){ //Operador multiplicación
  	temp = Complex();
  	temp.real = real * obj.real + imagin * obj.imagin;
  	temp.imagin = real * obj.imagin imagin * obj.real
  	return temp
}

Complex &Complex::operator/(const Complex &obj){ //Operador división
  	temp = Complex();
	temp.real = (real * obj.real + imagin * obj.imagin)/(obj.real * obj.real + obj.imagin * obj.imagin);
	temp.imagin = (-1.0 * real * obj.imagin + imagin * obj.real)/(obj.real * obj.real + obj.imagin * obj.imagin);	     return temp;		
}








