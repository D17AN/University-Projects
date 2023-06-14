#include<winsock2.h>
#include<stdio.h>
#include<stdlib.h>
#include <ws2tcpip.h>
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")
int main(){
	WSADATA wsadata;
	SOCKET client_socket = INVALID_SOCKET;
	int ires = WSAStartup(MAKEWORD(2, 2), &wsadata);
	if(ires != 0){
		printf("WsaStartup failed!\n");
		return -1;
	}

	struct addrinfo clientaddrinfo;
	ZeroMemory(&clientaddrinfo, sizeof(clientaddrinfo));
	clientaddrinfo.ai_family = AF_INET;
	clientaddrinfo.ai_socktype = SOCK_STREAM;
	clientaddrinfo.ai_protocol = 0;
	struct addrinfo* result = NULL;
	ires = getaddrinfo("172.30.112.178", "1234", &clientaddrinfo, &result);
	if(ires != 0) {
		printf("getaddrinfo failed with error: %d\n", ires);
		WSACleanup();
		return 1;
	}

	client_socket = socket(clientaddrinfo.ai_family, clientaddrinfo.ai_socktype, clientaddrinfo.ai_protocol);
	if(client_socket == INVALID_SOCKET){
		printf("socket failed with error: %ld\n", WSAGetLastError());
		WSACleanup();
		return -1;
	}

	printf("Socket created succesfully.\n");
	ires = connect(client_socket, clientaddrinfo.ai_addr, clientaddrinfo.ai_addrlen);
	if(ires == SOCKET_ERROR){
		closesocket(client_socket);
		client_socket = INVALID_SOCKET;
		return -1;
	}
	return 0;
}