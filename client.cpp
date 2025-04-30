#include "shared.h"

int main()
{
    int clientSocket;
    sockaddr_in serverAddress;
    std::string str, serverIP;

    
    std::cout << "Input server IP\n";
    std::getline(std::cin, serverIP);
    if (serverIP == "self") serverIP = defineIP();

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(SERVER_PORT);
    serverAddress.sin_addr.s_addr = inet_addr(serverIP.c_str());
    
    while (true)
    {
        clientSocket = socket(AF_INET, SOCK_STREAM, 0);
        if (clientSocket < 0)
        {
            perror("clientSocket");
            exit(1);
        }

        if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0)
        {
            perror("connect");
            exit(2);
        }

        std::getline(std::cin, str);
        char message[str.size() + 1];
        strcpy(message, str.c_str());

        if (str == "exit") break;

        send(clientSocket, message, sizeof(message), 0);
        close(clientSocket);
    }

    
    return 0;
}