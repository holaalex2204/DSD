#include "Fecha.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
static const int diasMes[] = {0,31,28,31,30,31,30,30,31,30,31,30,31};
static const int diasMesBisiesto[] =  {0,31,28,31,30,31,30,30,31,30,31,30,31};
Fecha::Fecha(int dd, int mm, int aaaa): dia(dd), mes(mm), anio(aaaa)
{
	
	if((mm <1) || (mm >12))
	{
		cout << "Valor ilegal para el mes" << endl;
		exit(1);
	}
	if(anio <0){
		cout << "Valor ilegal para el año" << endl;
		exit(1);	
	}
	if(dd<1)
	{
		cout << "Valor ilegal para el dia" << endl;
		exit(1);
	}
	if(!((anio%4==0&&anio%100!=0) | anio%400==0)){
		//true si el año no es bisiesto
		if(dd > diasMesBisiesto[mm])
		{
			cout << "Valor ilegal para el dia" << endl;
			exit(1);		
		}
	}
	else
	{
		if(dd > diasMes[mm])
		{
			cout << "Valor ilegal para el dia" << endl;
			exit(1);		
		}	
	}
}
void Fecha::inicializaFecha(int dd, int mm, int aaaa)
{
	anio = aaaa;
	mes = mm;
	dia = dd;
	return;
}
void Fecha::muestraFecha()
{
	cout << "La fecha es(dia-mes-año): " << dia << "-" << mes << "-" << anio << endl;
	return;
}

int Fecha::convierte(){
	return anio*10000+mes*100+dia;

}

bool Fecha::leapyr(){
	bool res=false;
	if(anio%4==0&&anio%100!=0){
		res=true;
	}
	if (anio%400==0){
		res=true;
	}
	return res;
}
int Fecha::masViejaObj(Fecha f2)
{
	if(anio > f2.anio)
	{
		return 1;
	}
	if(f2.anio > anio)
	{
		return -1;
	}
	if(mes > f2.mes)
	{
		return 1;
	}
	if(f2.mes > mes)
	{
		return -1;
	}
	if(dia > f2.dia)
	{
		return 1;
	}
	if(f2.dia > dia)
	{
		return -1;
	}
	return 0;
}
int Fecha::masVieja( Fecha &f2)
{
	if(anio > f2.anio)
	{
		return 1;
	}
	if(f2.anio > anio)
	{
		return -1;
	}
	if(mes > f2.mes)
	{
		return 1;
	}
	if(f2.mes > mes)
	{
		return -1;
	}
	if(dia > f2.dia)
	{
		return 1;
	}
	if(f2.dia > dia)
	{
		return -1;
	}
	return 0;
}
int Fecha::masViejaC( Fecha *f2)
{
	if(anio > f2->anio)
	{
		return 1;
	}
	if(f2->anio > anio)
	{
		return -1;
	}
	if(mes > f2->mes)
	{
		return 1;
	}
	if(f2->mes > mes)
	{
		return -1;
	}
	if(dia > f2->dia)
	{
		return 1;
	}
	if(f2->dia > dia)
	{
		return -1;
	}
	return 0;
}