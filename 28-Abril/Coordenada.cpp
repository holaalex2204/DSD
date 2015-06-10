#include <iostream>
#include "Coordenada.h"
#include <math.h> 
using namespace std;
Coordenada::Coordenada(double xx, double yy) : x(xx), y(yy)
{ 
	dist= pow((xx*xx+yy*yy),.5);
}
bool Coordenada::miFuncion(Coordenada i , Coordenada j)
{
	return (i.obtenerDist() < j.obtenerDist());
}
double Coordenada::obtenerDist()
{
	return dist;
}
double Coordenada::obtenerX()
{

	return x;
}

double Coordenada::obtenerY()
{
	return y;
}
