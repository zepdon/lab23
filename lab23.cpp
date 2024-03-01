#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}

ComplexNumber operator+(double NUM,const ComplexNumber &c){
	return ComplexNumber(NUM+c.real,c.imag);
}

ComplexNumber operator-(double NUM,const ComplexNumber &c){
	return ComplexNumber(NUM-c.real,NUM-c.imag);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
	return ComplexNumber(real * c.real,imag * c.real);
}

ComplexNumber operator*(double NUM,const ComplexNumber &c){
	return ComplexNumber(NUM * c.real,NUM * c.imag);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
  double d = c.real * c.real + c.imag * c.imag;
  return ComplexNumber((real * c.real + imag * c.imag ) / d,(imag * c.real - real * c.imag ) / d);
}

ComplexNumber operator/(double number,const ComplexNumber &c){
  double d = c.real * c.real + c.imag * c.imag;
  return ComplexNumber(number * c.real / d,-number * c.imag / d);
}

bool ComplexNumber::operator==(const ComplexNumber &c){
  return real == c.real && imag == c.imag;
}

bool operator==(double NUM, const ComplexNumber &c) {
  return NUM == c.real && c.imag == 0;
}

double ComplexNumber::abs(){
  return sqrt(real*real+imag*imag);
}

#define M_PI 3.14159265358979323846
double ComplexNumber::angle(){
  return atan2(imag,real) * 180 / M_PI;
}
ostream &operator<<(ostream &os, const ComplexNumber &c) {
	if(c.real == 0){
		if(c.imag == 0){
			os << "0";
			return os;
		}else{
			if (c.imag >= 0)
        	os << c.imag << "i";
    		else
       		os << "-" << -c.imag << "i";
            return os;
		}
	}else{
		if(c.imag == 0){
			os << c.real;
			return os;
		}else{
			os << c.real;
			if (c.imag >= 0)
        	os << "+" << c.imag << "i";
    		else
       		os << "-" << -c.imag << "i";
            return os;			
		}		
	}
}

int main(){
	ComplexNumber a(1.5,2),b(3.2,-2.5),c(-1,1.2);	
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";
	cout << a+2.5 << "\n";
	cout << 2.5+a << "\n";
	cout << a-1.5 << "\n";
	cout << 1.5-a << "\n";
	cout << b+ComplexNumber(0,2.5) << "\n";
	cout << c-c << "\n";
	cout << "-----------------------------------\n";
	
	ComplexNumber d = (a+b)/c;
	ComplexNumber e = b/(a-c);
	cout << d << "\n";
	cout << e << "\n";
	cout << c*2 << "\n";
	cout << 0.5*c << "\n";
	cout << 1/c << "\n";
	cout << "-----------------------------------\n";
	
	cout << ComplexNumber(1,1).abs() << "\n";
	cout << ComplexNumber(-1,1).abs() << "\n";
	cout << ComplexNumber(1.5,2.4).abs() << "\n";
	cout << ComplexNumber(3,4).abs() << "\n";
	cout << ComplexNumber(69,-9).abs() << "\n";		
	cout << "-----------------------------------\n";	
	
	cout << ComplexNumber(1,1).angle() << "\n";
	cout << ComplexNumber(-1,1).angle() << "\n";
	cout << ComplexNumber(-1,-1).angle() << "\n";
	cout << ComplexNumber(1,-1).angle() << "\n";
	cout << ComplexNumber(5,2).angle() << "\n";
	cout << "-----------------------------------\n";
	
	cout << (ComplexNumber(1,1) == ComplexNumber(1,2)) << "\n";
	cout << (ComplexNumber(1,1) == 1) << "\n";
	cout << (0 == ComplexNumber()) << "\n";
}