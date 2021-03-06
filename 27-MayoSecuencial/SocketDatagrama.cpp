#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <arpa/inet.h>
	SocketDatagrama::SocketDatagrama(int puerto)
	{
		s = socket(AF_INET, SOCK_DGRAM, 0);
		struct timeval tiempofuera;
		tiempofuera.tv_sec = 3;
    	tiempofuera.tv_usec = 0;
		setsockopt(s,SOL_SOCKET,SO_RCVTIMEO,(char*)&tiempofuera,sizeof(tiempofuera));
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
		p.inicializaDatos(new char[5]);
		return recvfrom(s, p.obtieneDatos(), p.obtieneLongitud() * sizeof(char) , 0, NULL, NULL);
	}
	int SocketDatagrama::envia(PaqueteDatagrama & p, char* ip )
	{
		direccionForanea.sin_addr.s_addr = inet_addr(ip);
		return sendto(s, p.obtieneDatos(), p.obtieneLongitud() * sizeof(char), 0, (struct sockaddr *) &direccionForanea, sizeof(direccionForanea));
	}