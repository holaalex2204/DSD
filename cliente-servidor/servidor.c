#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

int puerto = 7200;

int main(void)
{
   int num[2];
   int s, res, clilen;
   unsigned char dest[4];
   struct sockaddr_in server_addr, msg_to_client_addr;
   
   s = socket(AF_INET, SOCK_DGRAM, 0);
   
   /* se asigna una direccion al socket del servidor*/
   bzero((char *)&server_addr, sizeof(server_addr));
   server_addr.sin_family = AF_INET;
   server_addr.sin_addr.s_addr = INADDR_ANY;
   server_addr.sin_port = htons(puerto);
   bind(s, (struct sockaddr *)&server_addr, sizeof(server_addr));
   clilen = sizeof(msg_to_client_addr);
   while(1) {
      recvfrom(s, (char *) num, 2*sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, &clilen);
      res = num[0] + num[1];
       //printf("aqui\n");
       printf("%u\n",msg_to_client_addr.sin_addr.s_addr);
       memcpy(dest,&msg_to_client_addr.sin_addr.s_addr,4);
       
       for (int i=0; i<4; i++) {
           //printf("%d",i);
           printf(" %u",dest[i]);
       }
       
       printf("\n");
       
       printf("%d\n",ntohs(msg_to_client_addr.sin_port));
      /* envía la petición al cliente. La estructura msg_to_client_addr contiene la dirección socket del cliente */
      sendto(s, (char *)&res, sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, clilen);
   }
}

