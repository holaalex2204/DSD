#include <iostream>
#include "Coordenada3D.h"
#include <math.h> 
using namespace std;
Coordenada3D::Coordenada3D(double xx, double yy, double zz) : x(xx), y(yy), z(zz)
{ }
double Coordenada3D::obtenerX()
{
	return x;
}
double Coordenada3D::obtenerY()
{
	return y;
}
double Coordenada3D::obtenerZ()
{
	return z;
}