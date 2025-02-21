#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber {				
	public:
		double real;
		double imag;
		
		ComplexNumber(double = 0, double = 0);
		
		ComplexNumber operator+(const ComplexNumber &) const;
		ComplexNumber operator-(const ComplexNumber &) const;
		ComplexNumber operator*(const ComplexNumber &) const;
		ComplexNumber operator/(const ComplexNumber &) const;
		bool operator==(const ComplexNumber &) const;

		ComplexNumber operator+(double) const;
		ComplexNumber operator-(double) const;
		ComplexNumber operator*(double) const;
		ComplexNumber operator/(double) const;

		friend ComplexNumber operator+(double, const ComplexNumber &);
		friend ComplexNumber operator-(double, const ComplexNumber &);
		friend ComplexNumber operator*(double, const ComplexNumber &);
		friend ComplexNumber operator/(double, const ComplexNumber &);
		friend bool operator==(double, const ComplexNumber &);

		double abs() const;
		double angle() const;

		friend ostream& operator<<(ostream &, const ComplexNumber &);
};

ComplexNumber::ComplexNumber(double x, double y) {
	real = x; 
	imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c) const {
	return ComplexNumber(real + c.real, imag + c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c) const {
	return ComplexNumber(real - c.real, imag - c.imag);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c) const {
	return ComplexNumber(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c) const {
	double denominator = c.real * c.real + c.imag * c.imag;
	return ComplexNumber((real * c.real + imag * c.imag) / denominator, 
                         (imag * c.real - real * c.imag) / denominator);
}

bool ComplexNumber::operator==(const ComplexNumber &c) const {
	return (real == c.real) && (imag == c.imag);
}

ComplexNumber ComplexNumber::operator+(double x) const {
	return ComplexNumber(real + x, imag);
}

ComplexNumber ComplexNumber::operator-(double x) const {
	return ComplexNumber(real - x, imag);
}

ComplexNumber ComplexNumber::operator*(double x) const {
	return ComplexNumber(real * x, imag * x);
}

ComplexNumber ComplexNumber::operator/(double x) const {
	return ComplexNumber(real / x, imag / x);
}

ComplexNumber operator+(double x, const ComplexNumber &c) {
	return ComplexNumber(x + c.real, c.imag);
}

ComplexNumber operator-(double x, const ComplexNumber &c) {
	return ComplexNumber(x - c.real, -c.imag);
}

ComplexNumber operator*(double x, const ComplexNumber &c) {
	return ComplexNumber(x * c.real, x * c.imag);
}

ComplexNumber operator/(double x, const ComplexNumber &c) {
	double denominator = c.real * c.real + c.imag * c.imag;
	return ComplexNumber((x * c.real) / denominator, (-x * c.imag) / denominator);
}

bool operator==(double x, const ComplexNumber &c) {
	return (x == c.real) && (c.imag == 0);
}

double ComplexNumber::abs() const {
	return sqrt(real * real + imag * imag);
}

double ComplexNumber::angle() const {
	return atan2(imag, real) * (180 / M_PI);
}

ostream& operator<<(ostream &os, const ComplexNumber &c) {
	if (c.imag == 0) {
		os << c.real;
	} else if (c.real == 0) {
		os << c.imag << "i";
	} else {
		os << c.real;
		if (c.imag > 0) os << "+";
		os << c.imag << "i";
	}
	return os;
}