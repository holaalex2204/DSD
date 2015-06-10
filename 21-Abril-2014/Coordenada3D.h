#ifndef COORDENADA3D_H_
#define COORDENADA3D_H_ 
class Coordenada3D
{
private:

	double x;
	double y;
	double z;
public:
	Coordenada3D(double xx = 0, double yy= 0, double zz= 0);
	double obtenerX();
	double obtenerY();
	double obtenerZ();
};
#endif
