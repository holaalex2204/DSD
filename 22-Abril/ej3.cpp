#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include "Poligono.h"
using namespace std;
int main()
{
	srand(time(NULL));
	vector<Poligono> pol;
	//pol.reserve(30);
	for(int i = 0 ; i<100000; i++)
	{	
		pol.push_back(Poligono());
		for(int j = rand()%100 ; j>0;j--)
		{
			pol[i].anadeVertice(Coordenada(rand(),rand()));
		}
	}
	cout << "La cantidad de vertices es" << Poligono::cantVertices << endl;
	return 0;	
}