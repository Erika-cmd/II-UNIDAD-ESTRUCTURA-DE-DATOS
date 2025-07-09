#include <iostream>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main() {
    WSADATA wsa;
    SOCKET sock;
    struct sockaddr_in server;

    const char* server_ip = "10.203.54.70";
    int numero;

    cout << "Iniciando cliente...\n";
    cout << "Ingrese un número para enviar al servidor: ";
    cin >> numero;

    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0) {
        cout << "Error al iniciar Winsock.\n";
        return 1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET) {
        cout << "Error al crear socket.\n";
        return 1;
    }

    server.sin_addr.s_addr = inet_addr(server_ip);
    server.sin_family = AF_INET;
    server.sin_port = htons(8888);

    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        cout << "? No se pudo conectar al servidor.\n";
        closesocket(sock);
        WSACleanup();
        return 1;
    }

    send(sock, (char*)&numero, sizeof(numero), 0);
    cout << "? Numero enviado: " << numero << endl;

    closesocket(sock);
    WSACleanup();
    return 0;
}

