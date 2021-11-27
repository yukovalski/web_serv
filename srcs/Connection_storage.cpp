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

Connection_storage&	Connection_storage::operator=(const Connection_storage &other)
{
	_connections = other._connections;
	return *this;
}

Connection&			Connection_storage::operator[](size_t i) { return *_connections[i]; }

void 				Connection_storage::add_new_connection(listen_map::iterator sock, int kq)
{
	Connection		*new_conn = new Connection(sock->first, sock->second.first, sock->second.second);
	struct kevent	changelist;

	_connections[new_conn->getFd()] = new_conn;

	memset(&changelist, 0, sizeof(changelist));
	EV_SET(&changelist, new_conn->getFd(), EVFILT_READ, EV_ADD, 0, 0, 0);
	if (kevent(kq, &changelist, 1, NULL, 0, NULL) == -1)
		throw std::runtime_error ("add event to kqueue failed");
	std::cout << "add " << changelist.ident << " fd to track" << std::endl;
}