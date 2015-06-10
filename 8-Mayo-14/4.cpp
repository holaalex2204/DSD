#include <iostream>
#include <cmath>
using namespace std;
const long double PI = acos(-1.0);
class PoligonoRegular
{
private:
	long double alpha;
	int numLados;
public:
	PoligonoRegular(int cantLados =3);
	long double calcval();
	double calcArea();
};
PoligonoRegular::PoligonoRegular(int cantLados) : numLados(cantLados), alpha(2*PI/cantLados)
{ }
long double PoligonoRegular::calcval() //Calcula el área del círculo
{
	return(numLados*sinl(alpha/2)*cosl(alpha/2));
}
double PoligonoRegular::calcArea() //Calcula el área del círculo
{
	return(numLados*sin(alpha/2)*cos(alpha/2));
}
int main()
{
	cout.precision(40);
	PoligonoRegular pol;
	for(int i = 30 ; i<=100000000;i+=1000)
	{
		pol = PoligonoRegular(i);
		cout << "Para i = " << i << ", PiLong es: \t" << pol.calcval() << endl;
		cout << "Para i = " << i << ", Pidouble es: \t" << pol.calcArea() << endl;
	}
	return 0;
}