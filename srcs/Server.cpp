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

Server::Server(const std::vector<t_server>& config) :	_config(config)
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
//	struct kevent		events[MAX_EVENT];
	_kq = kqueue();
	_fds.reserve(MAX_EVENT);

	_listening_sockets = create_listening_sockets(_config);
	loop();
    return true;
}

void 	Server::loop()
{

}

//	int 		ret = 0;
//	char		buf[BUFFER_SIZE + 1];
//	std::string str;
//
//	while (true)
//	{
//		ret = recv(fd, buf, BUFFER_SIZE, 0);
//		if (ret < 0 && errno != EWOULDBLOCK)
//			throw "recv() failed";
//		if (ret < 0)
//			break ;
//		if (ret == 0)
//		{
//			std::cout << "Connection closed" << std::endl;
//			for (std::vector<pollfd>::iterator i = _fds.begin(); i != _fds.end(); ++i)
//			{
//				if (i->fd == fd)
//					_fds.erase(i);
//			}
//			break ;
//		}
//		if (ret > 0)
//		{
//			buf[ret] = 0;
//			str.append(buf, ret);
//		}
//	}
//	std::cout << "str: " << str << std::endl;
//	_request_buffers[fd].push_back(str);


