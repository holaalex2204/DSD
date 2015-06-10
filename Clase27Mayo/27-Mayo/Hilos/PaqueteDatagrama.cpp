#include "PaqueteDatagrama.h"
#include <iostream>
#include <cstring>
using namespace std;
PaqueteDatagrama::PaqueteDatagrama(unsigned char * mensaje, unsigned int longitud, unsigned char * ip, int puerto )
{
	int s, num[2];
	this->longitud = longitud;
	if(this->longitud <0)
	{
		this->longitud = 0;
	}
	inicializaDatos(mensaje);
	inicializaIp(ip);
	this->puerto = puerto;
}
PaqueteDatagrama::PaqueteDatagrama(unsigned int longitud)
{
	int s, num[2];
	this->longitud = longitud;
	if(this->longitud <0)
	{
		this->longitud = 0;
	}
	datos = new unsigned char[(this->longitud)];
	this->puerto = 7200;
	unsigned char* auxiliar = "192.168.0.101 ";
	for(int i = 0 ; i<strlen(auxiliar); i++)
	{
		ip[i] = auxiliar[i];
	}
	for(int i = 0 ; i<longitud; i++)
	{
		datos[i] = 0;
	}
}
PaqueteDatagrama::~PaqueteDatagrama()
{
	delete datos;
}
unsigned char* PaqueteDatagrama::obtieneDireccion()
{
	return ip;
}
unsigned int PaqueteDatagrama::  obtieneLongitud()
{
	return longitud;
}
int PaqueteDatagrama:: obtienePuerto()
{
	return puerto;
}
unsigned char* PaqueteDatagrama:: obtieneDatos()
{
	return this->datos;
}
void PaqueteDatagrama:: inicializaPuerto(int puerto)
{
	this->puerto = puerto;
}
void PaqueteDatagrama:: inicializaIp( unsigned char * ip)
{
	for(int i = 0 ; i<strlen(ip); i++)
	{
		this->ip[i] = ip[i];		
	}
}
void PaqueteDatagrama:: inicializaDatos(unsigned char *mensaje)
{
	this->datos = new unsigned char[(this->longitud+1)];
	for(int i = 0 ; i<=longitud; i++)
	{
		this->datos[i] = mensaje[i];
	}
}