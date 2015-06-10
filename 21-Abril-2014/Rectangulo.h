#include "Coordenada.h"
#ifndef RECTANGULO_H_
#define RECTANGULO_H_ 
class Rectangulo
{
private:

	Coordenada superiorIzq;

	Coordenada inferiorDer;
public:

	Rectangulo();
	Rectangulo(Coordenada a, Coordenada b);
	Rectangulo(double xSupIzq, double ySupIzq, double xInfDer, double yInfDer);

	void imprimeEsq();

	Coordenada obtieneSupIzq();

	Coordenada obtieneInfDer();
	double obtieneArea();
};
#endif
