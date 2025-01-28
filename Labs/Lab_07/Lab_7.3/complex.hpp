#ifndef COMPLEX_HPP
#define COMPLEX_HPP

class Complex
{
  private:
  	int m_n;
  public:
	double real; // Número real
	double imagin; // Número imaginario
	double conjugate(); // Obtención del conjugado
  	double norm(); //Sacar la norma
	Complex(double real, double imagin); //Custom Constructor
	~Complex(); //Destructor
	float *data()
	Complex(const Complex &obj); //Copy constructor
	Complex &operator(const Complex &obj); //Assignment opepator
	Complex &operator+(const Complex &obj); //Sumation
	Complex &operator-(const Complex &obj); //Sustraction
	Complex &operator*(const Complex &obj); //Multiplication
	Complex &operator/(const Complex &obj); //Division
}
#endif
