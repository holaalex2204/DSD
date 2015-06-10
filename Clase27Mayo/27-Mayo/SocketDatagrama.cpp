#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <arpa/inet.h> 
#include <string.h> 
	SocketDatagrama::SocketDatagrama(int puerto)
	{
		s = socket(AF_INET, SOCK_DGRAM, 0);
		struct timeval tiempofuera;
		tiempofuera.tv_sec = 5;
    	tiempofuera.tv_usec = 0;
    	int yes = 1;
    	setsockopt(s,SOL_SOCKET,SO_BROADCAST,&yes,sizeof(int));
		setsockopt(s,SOL_SOCKET,SO_RCVTIMEO,&tiempofuera,sizeof(tiempofuera));
   		bzero((char *)&direccionLocal, sizeof(direccionLocal));
	   	direccionLocal.sin_family = AF_INET;
	   	direccionLocal.sin_addr.s_addr = INADDR_ANY;
	   	direccionLocal.sin_port = htons(puerto);

	   	direccionForanea.sin_family = AF_INET;
	   	direccionForanea.sin_addr.s_addr = inet_addr("192.168.0.100");
	   	direccionForanea.sin_port = htons(7200);
	   	
	   	bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal));	
	}
	SocketDatagrama::~SocketDatagrama()
	{
		//close(s);
	}
	int SocketDatagrama::recibe(PaqueteDatagrama & p)
	{
		p.inicializaDatos(new unsigned char[5]);
		socklen_t aux ;
		aux = sizeof(direccionForanea);
		int a =  recvfrom(s, p.obtieneDatos(), p.obtieneLongitud() * sizeof(char) , 0, (struct sockaddr*)&direccionForanea, &aux);
		unsigned char*  dest = new unsigned char[4];
		memcpy(dest,&direccionForanea.sin_addr.s_addr,4);
		p.inicializaIp(dest);
		//memcpy(p.obtieneDireccion(),&direccionForanea.sin_addr.s_addr,4);
		return a;
	}
	int SocketDatagrama::envia(PaqueteDatagrama & p, char* ip )
	{
		direccionForanea.sin_addr.s_addr = inet_addr(ip);
		return sendto(s, p.obtieneDatos(), p.obtieneLongitud() * sizeof(char), 0, (struct sockaddr *) &direccionForanea, sizeof(direccionForanea));
	}