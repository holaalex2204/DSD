#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>

int puerto = 7200;

int main(void)
{
 
  for (int j=0; j<3; j++) {
    
    
    struct sockaddr_in msg_to_server_addr, client_addr;
    int s, num[2], res;
    unsigned char dest[4];
    char ip[16];
    
    scanf("%s",&ip);
    
    s = socket(AF_INET, SOCK_DGRAM, 0);
   /* rellena la dirección del servidor */
    bzero((char *)&msg_to_server_addr, sizeof(msg_to_server_addr));
    msg_to_server_addr.sin_family = AF_INET;
    msg_to_server_addr.sin_addr.s_addr = inet_addr(ip);
    msg_to_server_addr.sin_port = htons(puerto);
    
   /* rellena la direcciòn del cliente*/
    bzero((char *)&client_addr, sizeof(client_addr));
    client_addr.sin_family = AF_INET;
    client_addr.sin_addr.s_addr = INADDR_ANY;
    
   /*cuando se utiliza por numero de puerto el 0, el sistema se encarga de asignarle uno */
    client_addr.sin_port = htons(7777);
    bind(s, (struct sockaddr *)&client_addr,sizeof(client_addr));
    num[0] = 2;
   num[1] = 5; /*rellena el mensaje */
    sendto(s, (char *)num, 2 * sizeof(int), 0, (struct sockaddr *) &msg_to_server_addr, sizeof(msg_to_server_addr));
    
   /* se bloquea esperando respuesta */
    recvfrom(s, (char *)&res, sizeof(int), 0, NULL, NULL);
    printf("Aqui\n");
    //printf("%u\n",msg_to_server_addr.sin_addr.s_addr);

    memcpy(dest,&msg_to_server_addr.sin_addr.s_addr,4);
    
    printf("2 + 5 = %d\n", res);
    
    printf("Aqui\n");
    
    for (int i=0; i<4; i++) {
        //printf("%d",i);
      printf(" %u",dest[i]);
    }
    
    printf("\n puerto: %d\n",ntohs(msg_to_server_addr.sin_port));
    
    printf("\n");
    
    
    
    close(s);
  }
}

