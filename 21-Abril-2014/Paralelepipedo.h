#include "Coordenada3D.h"
#ifndef PARALELEPIPEDO_H_
#define PARALELEPIPEDO_H_ 
class Paralelepipedo
{
private:
	Coordenada3D u;
	Coordenada3D v;
	Coordenada3D w;
public:
	Paralelepipedo();
	Paralelepipedo(Coordenada3D a, Coordenada3D b, Coordenada3D c);
	double obtieneArea();
	double obtieneVolumen();
};
#endif
