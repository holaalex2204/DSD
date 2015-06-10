#include <stdio.h>
#include <stdlib.h>
#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

char * intToString(int num)
{
	char* arr = new char[3];
	arr[0] = (num/100) +48;
	arr[1] = ((num%100)/10) +48;
	arr[2] = ((num%10)) +48;
	return arr;
}
int main()
{
	//SocketDatagrama socket  = NULL;
	char ipParcial[] = "192.168.0.255";
	char* ip = new char[18];
	int num[2];
	char* aux;
	int ultOcteto;
	printf("Ingresa un numero \n");
	scanf("%d",&num[0]);
	printf("Ingresa un numero \n" );
	scanf("%d",&num[1]);
	aux = (char *)num;
	PaqueteDatagrama paqueteRecibir = PaqueteDatagrama(4);
	PaqueteDatagrama paqueteEnviar = PaqueteDatagrama((char*)num,(sizeof(num)/sizeof(char)),ipParcial,7200);
	SocketDatagrama socket= SocketDatagrama(7200);
	int nume = 0;
    socket.envia(paqueteEnviar);
    printf("Enviando petición a : %s\n",paqueteEnviar.obtieneDireccion());
    for(;;)
	{	
        pid_t pid;
		int estado = 0;
		pid= fork();
		switch(pid){
			case -1:
                printf("-1\n");
                exit(0);
				break;
			case 0:
				socket.recibe(paqueteRecibir);
				nume = 0;
				memcpy(&nume,paqueteRecibir.obtieneDatos(),sizeof(int));
				printf("Respuesta de %s : %d\n",paqueteRecibir.obtieneDireccion(),nume);
				break;
			default:
                printf("esperando...\n");
				wait(&estado);
				break;
		}
	}
	return 0;
}