#include<cstdio>
#include<iostream>

class Complex
{
	private:
		
		friend Complex operator + (const Complex& a, const Complex& b);
		friend Complex operator - (const Complex& a, const Complex& b);
		friend Complex operator * (const Complex& a, const Complex& b);
		friend Complex operator / (const Complex& a, const Complex& b);
		friend std::ostream& operator << (const std::ostream& out, const Complex& comp);
		friend std::istream& operator >> (const std::istream& in, Complex& comp);
	
	
}
