#include<stdio.h>
#include<bits/stdc++.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>

#define PORT 20001
#define MAXLINE 1024

int main(){
    printf("UDP server \n");

    // all the neccessary variables
    int sockfd;
    char buffer[MAXLINE];
    const char *hello = "Hello form server";
    struct sockaddr_in serveraddr, cliaddr;

    // Creating socket file descriptor
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd < 0){
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Allocating memory
    memset(&serveraddr, 0, sizeof(serveraddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    //Filling server information
    serveraddr.sin_family = AF_INET; // IPv4
    serveraddr.sin_addr.s_addr = INADDR_ANY;
    serveraddr.sin_port = htons(PORT); 

    // Bind the socket with the server address
    int is_bind = bind(sockfd, (const struct sockaddr *)&serveraddr, sizeof(serveraddr));
    if (is_bind < 0){
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    socklen_t len;
    int n;
    len = sizeof(cliaddr);
    n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *)&cliaddr, &len);
    
    buffer[n] = '\0';
    printf("Client: %s\n", buffer);

    sendto(sockfd, (const char *)hello, strlen(hello), MSG_CONFIRM, (const struct sockaddr *) &cliaddr, len);
    std::cout<<"Hello message sent"<<std::endl;

    return 0;
}