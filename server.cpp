#include "shared.h"

int main()
{
    int serverSocket, clientSocket;
    sockaddr_in serverAddress;
    char buffer[1 << 15];
    std::ofstream file("server.log", std::ios::app);
    
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0)
    {
        perror("serverSocket");
        exit(1);
    }
    
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(SERVER_PORT);
    serverAddress.sin_addr.s_addr = inet_addr(defineIP().c_str());
    
    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0)
    {
        perror("bind");
        exit(2);
    }

    listen(serverSocket, 1);

    while (true)
    {
        clientSocket = accept(serverSocket, nullptr, nullptr);
        if (clientSocket < 0)
        {
            perror("accept");
            exit(3);
        }

        recv(clientSocket, buffer, sizeof(buffer), 0);

        std::cout << "Message from client: " << buffer << std::endl;

        file << buffer << std::endl;
        if (!strncmp(buffer, "return 0", 8)) break;
    }

    file.close();

    close(serverSocket);

    return 0;
}