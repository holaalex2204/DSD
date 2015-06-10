#ifndef PAQUETE_DATAGRAMA_H
#define PAQUETE_DATAGRAMA_H
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
class PaqueteDatagrama {
public:
	PaqueteDatagrama(char *, unsigned int, char *, int );
	PaqueteDatagrama(unsigned int );
	~PaqueteDatagrama();
	char *obtieneDireccion();
	unsigned int obtieneLongitud();
	int obtienePuerto();
	char *obtieneDatos();
	void inicializaPuerto(int);
	void inicializaIp(char *);
	void inicializaDatos(char *);
private:
	struct sockaddr_in msg_to_server_addr;
	struct sockaddr_in client_addr;
	struct sockaddr_in server_addr, msg_to_client_addr;
	char *datos;
//Almacena los datos
	char ip[16];
//Almacena la IP
	unsigned int longitud;
//Almacena la longitude de la cadena de datos
	int puerto;
//Almacena el puerto
};
#endif