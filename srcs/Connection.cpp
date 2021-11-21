//
// Created by Sergey Uryashev on 21.11.2021.
//

#include "../includes/Connection.hpp"

Connection::Connection(int fd, int host, int port)
	: _fd(fd), _host(host), _port(port), _status(LISTENING)
{}

Connection::~Connection()
{}

