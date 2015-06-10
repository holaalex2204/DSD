#include "Paralelepipedo.h"
#include "Coordenada3D.h"
Paralelepipedo::Paralelepipedo(){

}
Paralelepipedo::Paralelepipedo(Coordenada3D a, Coordenada3D b, Coordenada3D c) : u(a), v(b), w(c)
{

}
double Paralelepipedo::obtieneArea(){
	return 0;
}
double Paralelepipedo::obtieneVolumen()
{
	return (u.obtenerX()*v.obtenerY()*w.obtenerZ() + v.obtenerX()*w.obtenerY()*u.obtenerZ() + w.obtenerX()*u.obtenerY()*v.obtenerZ() 
	-u.obtenerX()*w.obtenerY()*v.obtenerZ() - v.obtenerX()*u.obtenerY()*w.obtenerZ() - w.obtenerX()*v.obtenerY()*u.obtenerZ());
}
