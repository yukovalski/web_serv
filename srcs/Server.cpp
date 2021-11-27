/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <sgath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 19:14:59 by sgath             #+#    #+#             */
/*   Updated: 2021/09/12 15:55:28 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

Server::Server(const std::vector<t_server>& config) :	_config(config), _fds_size(0)
{
	_connections = new Connection_storage;
	std::cout << "server object was created" << std::endl;
}

Server::Server(const Server &v) :
	_config(v._config),
	_htmlData(v._htmlData)
{}

Server&	Server::operator=(const Server &v)
{
    if (&v != this){
        _config = v._config;
        _htmlData = v._htmlData;
    }
    return (*this);
}

Server::~Server()
{}

bool	Server::start()
{
	_kq = kqueue();

	if (_kq == -1)
		throw std::runtime_error("kqueue() failed");
	_listening_sockets = create_listening_sockets(_config);
	add_listening_sockets_to_track();
	loop();
    return true;
}

void 	Server::loop()
{
	struct kevent	events[MAX_EVENT];
	int 			events_count;

	while(true)
	{
		std::cout << "waiting..." << std::endl;
		events_count = kevent(_kq, NULL, 0, events, MAX_EVENT, NULL);
		if (events_count == -1)
			throw std::runtime_error("kevent() failed");
		handle_events(events, events_count);
	}
}

void 	Server::handle_events(struct kevent* events, int count)
{
	int						fd;
	listen_map::iterator	it;

	for (int i = 0; i < count; ++i)
	{
		fd = events[i].ident;
		std::cout << "event on " << fd << " fd" << std::endl;
		if (events[i].flags & EV_ERROR)
			throw std::runtime_error("event error");
		it = _listening_sockets.find(fd);
		if (it != _listening_sockets.end())
			_connections->add_new_connection(it, _kq);
		else
			(*_connections)[fd].read_request();
	}
}

void 	Server::add_listening_sockets_to_track()
{
	listen_map::iterator	i;

	for (i = _listening_sockets.begin(); i != _listening_sockets.end(); ++i)
	{
		struct kevent	changelist;

		memset(&changelist, 0, sizeof(changelist));
		EV_SET(&changelist, i->first, EVFILT_READ, EV_ADD, 0, 0, 0);
		if (kevent(_kq, &changelist, 1, NULL, 0, NULL) == -1)
			throw std::runtime_error ("add event to kqueue failed");
		std::cout << "add " << changelist.ident << " fd to track" << std::endl;
	}
}

void 	Server::add_kevent_struct(struct kevent k)
{
	_fds[_fds_size++] = k;
}

