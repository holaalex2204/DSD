#include "SocketDatagrama.h"
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <netdb.h>
#include <strings.h>
#include <iostream>
#include <errno.h>

using namespace std;

SocketDatagrama::SocketDatagrama(int puertoL)
{
    
    struct timeval tiempofuera;
    tiempofuera.tv_sec = 2;
    tiempofuera.tv_usec = 2;
    int yes = 1;
   s = socket(AF_INET, SOCK_DGRAM, 0);
   
   bzero((char *)&direccionLocal, sizeof(struct sockaddr_in));
   bzero((char *)&direccionForanea, sizeof(struct sockaddr_in));      

   direccionLocal.sin_family = AF_INET;
   direccionLocal.sin_addr.s_addr = INADDR_ANY;
   direccionLocal.sin_port = htons(puertoL);
   bind(s, (struct sockaddr *)&direccionLocal,sizeof(direccionLocal));
}

SocketDatagrama::~SocketDatagrama()
{
   close(s);
}

//Recibe un paquete tipo datagrama proveniente de este socket
int SocketDatagrama::recibe(PaqueteDatagrama & p)
{
   int retorno;
   socklen_t clilen; //Ojo no compila si es un tipo int en C
   clilen = sizeof(direccionForanea);
   retorno = recvfrom(s, (char *) p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, &clilen);
   p.inicializaPuerto(ntohs(direccionForanea.sin_port));
   p.inicializaIp(inet_ntoa(direccionForanea.sin_addr));
   
   return retorno;
}

//Envía un paquete tipo datagrama desde este socket
int SocketDatagrama::envia(PaqueteDatagrama & p)
{
   direccionForanea.sin_family = AF_INET;
   direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
   direccionForanea.sin_port = htons(p.obtienePuerto());
   sendto(s, (char *)p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *) &direccionForanea, sizeof(direccionForanea));
}
