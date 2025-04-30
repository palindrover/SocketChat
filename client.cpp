#include "shared.h"

int main()
{
    int clientSocket;
    sockaddr_in serverAddress;
    std::string str, serverIP;

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0)
    {
        perror("clientSocket");
        exit(1);
    }

    std::cout << "Input server IP\n";
    std::cin >> serverIP;

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(SERVER_PORT);
    serverAddress.sin_addr.s_addr = inet_addr(serverIP.c_str());
    
    if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0)
    {
        perror("connect");
        exit(2);
    }

    std::cin >> std::ws;
    std::cin >> str;
    char message[str.size() + 1];
    strcpy(message, str.c_str());

    send(clientSocket, message, sizeof(message), 0);

    close(clientSocket);

    return 0;
}