/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu <yu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 18:01:09 by sgath             #+#    #+#             */
/*   Updated: 2021/09/11 23:11:36 by yu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
#define SERVER_HPP

#include "Webserv.hpp"

class Socket;
class Request;
class Connection;

class			Server
{
	typedef std::map<int, std::pair<std::string, int> >		listen_map;

private:
	int 										_kq;
	std::vector<t_server>						_config;
	std::string									_htmlData;
	struct kevent								_fds[CONN_NUMBER];
	size_t 										_fds_size;
	listen_map									_listening_sockets;
	std::map<int, Connection>					_connections;

	Server();

public:

	Server(const std::vector<t_server>& config);
	Server(const Server &v);
	~Server();

	Server&		operator=(const Server &v);

	bool		start();

private:
	void 		loop();
	void 		handle_events(struct kevent* events, int count);
	void 		add_listening_sockets_to_track();

};

#endif