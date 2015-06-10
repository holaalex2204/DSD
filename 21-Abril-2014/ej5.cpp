#include <iostream>
#include "Coordenada3D.h"
#include "Paralelepipedo.h"
using namespace std;
int main( )
{
	Paralelepipedo p(Coordenada3D(3,-2,5),Coordenada3D(2,2,-1),Coordenada3D(-4,3,2));
	cout << "El volumen del Paralelepipedo es = " << p.obtieneVolumen() << endl;
	return 0;
}


