/*
** EPITECH PROJECT, 2019
** Client.hpp
** File description:
** Client header file
*/

#ifndef CLIENT_HPP_
	#define CLIENT_HPP_

#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include "Raise.h"

class Client {
	public:
		Client(char *ip, int port);
		~Client();

        struct sockaddr_in getInfo(void) const;
        char *getIp(void) const;
        int getPort(void) const;
        int getSocket(void) const;
        void write(std::string msg) const;
        std::string read(void);

	protected:
        int Socket;
        int Port;
        char *Ip;
        struct sockaddr_in Info;
	private:
};

#endif /* !CLIENT_HPP_ */
