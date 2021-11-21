//
// Created by Sergey Uryashev on 21.11.2021.
//

#ifndef WEB_SERV_CONNECTION_H
#define WEB_SERV_CONNECTION_H

#define LISTENING	0
#define READING		1
#define COMPLETE	2
#define WRITING		3

class Connection
{
private:
	int 			_fd;
	std::string		_host;
	int 			_port;
	int 			_status;
	std::string		_request;
	std::string		_response;

	Connection();
	Connection(const Connection& conn);

	Connection&		operator=(const Connection& conn);

public:
	Connection(int fd, std::string host, int port);
	~Connection();

};


#endif //WEB_SERV_CONNECTION_H