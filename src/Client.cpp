/*
** EPITECH PROJECT, 2019
** Client.cpp
** File description:
** Client class file
*/

#include "../include/Client.hpp"

Client::Client(char *ip, int port) : Ip(ip), Port(port)
{
    this->Socket = socket(AF_INET, SOCK_STREAM, 0);
    if (this->Socket < 0)
        raise("Socket generation failed");
    this->Info.sin_family = AF_INET;
    this->Info.sin_port = htons(this->Port);
    this->Info.sin_addr.s_addr = inet_addr(this->Ip);
    if (connect(this->Socket, (struct sockaddr*)&this->Info, sizeof(this->Info)) < 0)
        raise("Connexion failed");
    this->read();
    this->write("GRAPHICAL");
}

Client::~Client()
{
}

struct sockaddr_in Client::getInfo(void) const { return this->Info; }
char *Client::getIp(void) const { return this->Ip; }
int Client::getPort(void) const { return this->Port; }
int Client::getSocket(void) const {return this->Socket; }

void Client::write(std::string msg) const
{
    int n = 0;
    int i = 0;
    char char_msg[msg.size() + 1];

    strcpy(char_msg, msg.c_str());
    if ((n = dprintf(this->Socket, "%s\n", char_msg)) < 0)
        raise("Write on server failed");
}

std::string Client::read(void)
{
    char buffer[4096];
    int n = 0;

    if ((n = recv(this->Socket, buffer, sizeof(buffer), 0)) < 0)
        raise("Read from server failed");
    buffer[n - 1] = '\0';
    std::string result(buffer);
    return result;
}