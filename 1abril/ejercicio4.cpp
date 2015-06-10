#include <iostream>
using namespace std;

int main(){

cout<<"Conversor grados celsius a fahrenheit"<<endl;
	
	double c=20;
	double f;

	f=(9/static_cast<double>(5)*c)+32.0;

	cout<<"Grados Celsius:"<<c<<endl;

	cout<<"Grados Fahrenheit:"<<f<<endl;

}
