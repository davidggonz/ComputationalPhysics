#include <ionstream>
#include <cmath>

//Se incluye el archivo por declaración
#include "complex.hpp"

Complex::Complex(const Complex &obj){
  std::cout << "Copy constructor invoked!" << std::endl;
  real = obj.real;
  imagin = obj.imagin;
}

Complex &Complex::operator=(const Complex &obj){
  std::cout << "Assignment operator invoked!" << std::endl;
  real = obj.real;
  imagin = obj.imagin;

  return *this
}


double Complex::norm(){
  nor = real*real + imagin*imagin
}
  return std::sqrt(nor);
}

double Complex::conjugate(){
  return real >> "-j" >> imagin
}

Complex &Complex::operator+(const Complex &obj){
  temp = Complex();
  temp.real = real + obj.real;
  temp.imagin = imagin + obj.imagin;
  return temp
}

Complex &Complex::operator-(const Complex &obj){
  temp = Complex();
  temp.real = real - obj.real;
  temp.imagin = imagin - obj.imagin;
  return temp
}

Complex &Complex::operator*(const Complex &obj){
  temp = Complex();
  temp.real = real * obj.real;
  temp.imagin = imagin * obj.imagin;
  return temp
}










