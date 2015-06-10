#include <vector>

#include "Coordenada.h"
using namespace std;
#ifndef POLIGONO2_H_
#define POLIGONO2_H_ 
class Poligono2
{
private:
	vector <Coordenada> vertices;
	int cuenta;
public:
	static int cantVertices;
	Poligono2();
	void imprimeVertices();
	void anadeVertice(Coordenada punto);

};
#endif
