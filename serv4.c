#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

struct sockaddr_in sa,ca; //server address, client address
int ss,sc; //socket server, socket client 
char co[100];
char merr[100];
printf("dsafgdasgfdagfdagad\n");

//krijohet socketi i serv socket()
ss = socket(AF_INET,SOCK_STREAM,0);
if(ss<0) {printf("nuk hapet socketi"); exit(1);}
else ("server socket: %d",ss);

//inicializohet socketi i serverit
sa.sin_family = AF_INET;
sa.sin_addr.s_addr = INADDR_ANY;
sa.sin_port = htons(55555);
printf("server  eshte ne porten ");

//behet bind(), pra lidhja me TPC
int b = bind(ss,(struct sockaddr*)&sa,sizeof(sa));
if(b<0) printf("su bo bind");
else printf("bind ne: %d",b);

//presim per klient listen()
listen(ss,5);

int k = 0;
while(k<3){
//prano kerkesen nga kli accept()
sc = accept(ss,(struct sockaddr*)&ca,sizeof(ca));
if(sc<0) printf("smund te bej accept");

read(sc,merr,100);
printf("msg nga kli: %s", merr);

sprintf(co,"Msg nga serveri: k= %d",k);
write(ss,co,strlen(co));
k++;
//mbyll socketin e kli
close(sc);
}
close(ss); return 0;
}
