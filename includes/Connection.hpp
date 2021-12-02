//
// Created by Sergey Uryashev on 21.11.2021.
//

#ifndef WEB_SERV_CONNECTION_H
#define WEB_SERV_CONNECTION_H

#define INCOMPLETE			0
#define COMPLETE			1
#define INVALID				2

#define DONT_CLOSE			0
#define SHOULD_BE_CLOSED	1
#define AFTER_SEND			2

#include "Webserv.hpp"

class Connection
{
private:
	int 						_fd;
	std::string					_host;
	int 						_port;
	int 						_status;
	std::string					_request;
	std::string					_response;
	std::map<int, std::string>	*_error_pages;
	int 						_close_connection_flag;

	Connection();
	Connection(const Connection& conn);

	Connection&		operator=(const Connection& conn);

public:
	Connection(int fd, std::string host, int port, std::map<int, std::string>* error_pages);
	~Connection();

	int 				getFd() const;
	int 				getPort() const;
	const std::string&	getHost() const;
	int 				getStatus() const;
	int 				getCloseConnectionFlag() const;
	std::string& 		getRequest();
	std::string&		getResponse();

	void 				setStatus(int status);

	void 				read_request(const struct kevent& event);
	void 				check_request();
	void 				send_response();
};


#endif //WEB_SERV_CONNECTION_H
