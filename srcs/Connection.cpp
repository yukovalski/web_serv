//
// Created by Sergey Uryashev on 21.11.2021.
//

#include "../includes/Connection.hpp"

Connection::Connection(int fd, std::string host, int port)
	: _fd(fd), _host(host), _port(port), _status(LISTENING)
{
	struct sockaddr	addr;
	socklen_t		len = sizeof(sockaddr);

	_fd = accept(fd, &addr, &len);
	if (_fd == -1)
		throw std::runtime_error("accept() failed");
}

Connection::~Connection()
{
	close(_fd);
	std::cout << "close connection on " << _fd << " fd." << std::endl;
}

int					Connection::getFd() const { return _fd; }
int 				Connection::getPort() const { return _port; }
const std::string&	Connection::getHost() const { return _host; }
int 				Connection::getStatus() const { return _status; }
std::string&		Connection::getRequest() { return _request; }
std::string&		Connection::getResponse() { return _response; }

void 				Connection::setStatus(int status) { _status = status; }

void 				Connection::read_request()
{
	int 	ret = BUFFER_SIZE;
	char 	buf[BUFFER_SIZE + 1];

	_request = "";
	std::cout << "read from " << _fd << " fd." << std::endl;
	while(ret == BUFFER_SIZE)
	{
		ret = recv(_fd, buf, BUFFER_SIZE, 0);
		if (ret == -1) {
			std::cerr << "recv() failed." << std::endl;
			return;
		}
		buf[ret] = 0;
		_request += buf;
	}
	send(_fd, _request.data(), _request.length(), 0);
}