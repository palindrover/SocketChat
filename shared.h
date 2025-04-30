#ifndef SHARED_H_
#define SHARED_H_


#include <sys/socket.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <linux/if.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <iostream>
#include <cstring>
#include <fstream>

#define SERVER_ADDRESS "server IP"
#define SERVER_PORT 8000

std::string defineIP();

#endif
