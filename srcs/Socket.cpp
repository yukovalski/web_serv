//
// Created by Mitchel Samual on 10/27/21.
//

#include "Socket.hpp"

Socket::Socket(int port, const std::string& host) :	_port(port),
													_host(host)
{
	int					ret, on = 1;
	struct sockaddr_in	addr;

	_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (_fd < 0)
		throw "Socket() failed";
	ret = setsockopt(_fd, SOL_SOCKET, SO_REUSEADDR, (char *)&on, sizeof(on));
	if (ret < 0)
		throw "setsockopt() failed";
	ret = fcntl(_fd, F_SETFL, O_NONBLOCK);
	if (ret < 0)
		throw "fcntl() failed";
	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
}

Socket::Socket(int fd, int port, const std::string& host) :	_fd(fd),
															_port(port),
															_host(host)
{}

Socket::~Socket()
{}

int Socket::getFd() const {
	return _fd;
}

void Socket::setFd(int fd) {
	_fd = fd;
}

int Socket::getPort() const {
	return _port;
}

void Socket::setPort(int port) {
	_port = port;
}
