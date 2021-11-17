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

class			Server
{
private:

	std::vector<t_server>						_config;
	std::string									_htmlData;
	std::vector<pollfd>							_fds;
	std::map<int, Request>						_requests;
	std::map<int, std::pair<std::string, int> >	_listening_sockets;

	Server();

public:

	Server(const std::vector<t_server>& config);
	Server(const Server &v);
	~Server();

	Server&		operator=(const Server &v);

	bool		start();
	void 		read_request(int fd);

};

#endif