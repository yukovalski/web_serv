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

Server::Server()
{}

Server::Server(const t_server& config) :	_config(config),
											_htmlData("HTTP/1.1 200 OK\nDate: Sat, 27 Oct 2021 16:58:49 GMT\nContent-Type: text/html\nContent-Length: 98\nConnection: keep-alive\n\n<html><body><p>Yulia - ZHOPA!!!</p></body></html>\n\n")
{
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
	_listening_socket = new Socket(_config.port, _config.host);
	std::cout << "server is started" << std::endl;
    return true;
}
