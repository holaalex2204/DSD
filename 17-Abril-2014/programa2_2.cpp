#include "Fecha.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
void pruebaConstructor()
{
	Fecha a;
	int dia, mes, anio;
	for(int i = 0 ; i<100;i++)
	{
		dia = rand()%33;
		mes = rand()%14;
		anio = rand()%2050;
		cout << "dia: " << dia << " mes: " << mes << " año: " << anio << endl;
		a =  Fecha(dia,mes,anio);
	}
}
void pruebaPorObjetos()
{
	Fecha fechasList[100];
	int dia, mes, anio;
	int posAleatoria;
	for(int i = 0 ; i<100;i++)
	{
		dia = rand()%28 +1;
		mes = rand()%12 +1;
		anio = rand()%2050 +1;
		fechasList[i] =  Fecha(dia,mes,anio);
	}
	for(int i = 0 ; i<100000000; i++){
		posAleatoria = rand()%100;
		fechasList[(i%100)].masViejaObj(fechasList[posAleatoria]);
	}
}
void pruebaPorReferencia()
{
	Fecha fechasList[100];
	int dia, mes, anio;
	int posAleatoria;
	for(int i = 0 ; i<100;i++)
	{
		dia = rand()%28 +1;
		mes = rand()%12 +1;
		anio = rand()%2050 +1;
		fechasList[i] =  Fecha(dia,mes,anio);
	}
	for(int i = 0 ; i<100000000; i++){
		posAleatoria = rand()%100;
		fechasList[(i%100)].masVieja(fechasList[posAleatoria]);
	}
}
void pruebaPorReferenciaC()
{
	Fecha fechasList[100];
	int dia, mes, anio;
	int posAleatoria;
	for(int i = 0 ; i<100;i++)
	{
		dia = rand()%28 +1;
		mes = rand()%12 +1;
		anio = rand()%2050 +1;
		fechasList[i] =  Fecha(dia,mes,anio);
	}
	for(int i = 0 ; i<100000000; i++){
		posAleatoria = rand()%100;
		fechasList[(i%100)].masViejaC(&fechasList[posAleatoria]);
	}
}
int main()
{
	srand(time(NULL));
	//pruebaConstructor();
	//pruebaPorReferencia();
	pruebaPorReferenciaC();
	//pruebaPorObjetos();
}
