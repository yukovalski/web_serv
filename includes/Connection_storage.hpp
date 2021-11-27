//
// Created by Mitchel Samual on 11/27/21.
//

#ifndef WEB_SERV_CONNECTION_STORAGE_H
#define WEB_SERV_CONNECTION_STORAGE_H

#include "Webserv.hpp"

class Connection_storage
{
private:
	std::map<int, Connection>	_connections;

public:
	Connection_storage();
	Connection_storage(const Connection_storage& other);
	~Connection_storage();

	Connection_storage&		operator=(const Connection_storage& other);

	Connection&				operator[](size_t i);
	void 					add_new_connection(int sd);
};


#endif //WEB_SERV_CONNECTION_STORAGE_H
