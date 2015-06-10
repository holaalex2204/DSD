#ifndef COORDENADA_H_
#define COORDENADA_H_ 
	class Coordenada
{
private:

	double x;
	double dist;
	double y;
public:

	Coordenada(double = 0, double = 0);
	static bool miFuncion(Coordenada i, Coordenada j);
	double obtenerX();
	double obtenerDist();
	double obtenerY();
};
#endif
