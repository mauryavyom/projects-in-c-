#include<stdio.h>
#include<string.h>
#include<winsock2.h>

#pragma comment(lib, "ws2_32.lib")
int main(){
    WSADATA wsa;
    SOCKET client_socket;
    struct sockaddr_in server_addr;
    char message[1024];
    char buffer[1024];
    int recv_size;

    // Step 1: initialize winsock.
    if(WSAStartup(MAKEWORD(2,2),&wsa)!=0){
        printf("initialization failed. Error code: %d\n", WSAGetLastError());
        return -1;
    }
    printf("Winsock initialized.\n");

    // step 2:create a socket.
    client_socket = socket(AF_INET,SOCK_STREAM,0);
    if(client_socket == INVALID_SOCKET){
        printf("Could not create a socket.Error code :\n",WSAGetLastError());
        WSACleanup();
        return 1;
    }
    printf("Socket created\n");

    // step 3:Setup the socket address in structure.
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(8080);

    // Step 4:connect to the server.
    if(connect(client_socket,(struct sockaddr *)&server_addr,sizeof(server_addr)) < 0){
        printf("FAiled to connect.Error code %d\n", WSAGetLastError());
        closesocket(client_socket);
        WSACleanup();
    }
    printf("Connected to server.\n");

    // step 5:Send a message.
    printf("Type your message :-");
    fgets(message,sizeof(message),stdin);
    
    if(send(client_socket, message,strlen(message),0)<0){
        printf("Send failed. Error code : %d\n",WSAGetLastError());
    }
    printf("Message sent.\n");
    
    // step 6: Receive a reply from the server.
    recv_size = recv(client_socket,buffer,sizeof(buffer),0);
    if(recv_size == SOCKET_ERROR){
        printf("Receive failed. Error code : %d\n",WSAGetLastError());
    }
    else{
        buffer[recv_size] = '\0';
        printf("Receved message : %s\n",buffer); 
           }

    //step 7: Close the socket and cleanup
    closesocket(client_socket);
    WSACleanup();       
    return 0;
}