#ifndef COMPLEX_HPP
#define COMPLEX_HPP

class Complex
{
  private:
  	int m_n; //Esto es solamente probando (no darle importancia)
  public:
	double real; // Número real
	double imagin; // Número imaginario
	double conjugate(); // Obtención del conjugado
  	double norm(); //Sacar la norma
	Complex(double real = 0.0, double imagin = 0.0); //Custom Constructor
	~Complex(); //Destructor
	float *data() //Esto es solamente probando (no darle importancia)
	Complex(const Complex &obj); //Copy constructor
	Complex &operator(const Complex &obj); //Assignment operator
	Complex operator+(const Complex &obj); //Sumation
	Complex operator-(const Complex &obj); //Sustraction
	Complex operator*(const Complex &obj); //Multiplication
	Complex operator/(const Complex &obj); //Division
}
#endif
