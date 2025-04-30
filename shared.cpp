#include "shared.h"

std::string defineIP()
{
    int fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_IP);

    struct ifreq ifr {};
    strcpy(ifr.ifr_name, "wlo1");
    ioctl(fd, SIOCGIFADDR, &ifr);
    close(fd);

    char ip[INET_ADDRSTRLEN];
    strcpy(ip, inet_ntoa(((sockaddr_in*)&ifr.ifr_addr)->sin_addr));

    return ip;
}