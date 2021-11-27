//
// Created by Mitchel Samual on 11/27/21.
//

#include "../includes/Connection_storage.hpp"

Connection_storage::Connection_storage()
{}

Connection_storage::Connection_storage(const Connection_storage &other) : _connections(other._connections)
{}

Connection_storage::~Connection_storage()
{}

Connection_storage&			operator=(const Connection_storage &other)
{
	_connections = other._connections;
	return *this;
}

Connection&					operator[](size_t i) { return _connections[i]; }

void 						Connection_storage::add_new_connection(int sd)
{
	Connection new_conn(sd);

	_connections[new_conn.getFd()] = new_conn;
}