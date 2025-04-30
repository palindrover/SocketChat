#!/bin/bash

g++ -g -Wall shared.cpp server.cpp -o server
g++ -g -Wall shared.cpp client.cpp -o client
