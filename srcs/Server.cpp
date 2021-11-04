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
	int		ret;
	int		current_size;
	Socket*	new_socket;
	_listening_socket = new Socket(_config.port, _config.host);

	std::cout << "Listening socket created on " << _listening_socket->getFd() << " fd" << std::endl;
	pollfd	*fds = new pollfd();
	fds->fd = _listening_socket->getFd();
	fds->events = POLLIN;
	_fds.push_back(*fds);
	while (true)
	{
		std::cout << "Waiting on poll ..." << std::endl;
		ret = poll(_fds.data(), _fds.size(), POLL_TIMEOUT);
		if (ret < 0)
			throw "poll() failed";
		if (ret == 0)
		{
			std::cout << "Timeout" << std::endl;
			break ;
		}
		current_size = _fds.size();
		for(int i = 0; i < current_size; ++i)
		{
			if (_fds[i].revents == 0)
				continue ;
			if (_fds[i].revents != POLLIN)
				throw "Error! revents" + std::to_string(_fds[i].revents);
			if (_fds[i].fd == _listening_socket->getFd())
			{
				std::cout << "listening socket is readable" << std::endl;
				while (true)
				{
					new_socket = _listening_socket->new_connection();
					if (!new_socket)
						break ;
					fds->fd = new_socket->getFd();
					fds->events = POLLIN;
					_fds.push_back(*fds);
				}
			}
			else
			{
				std::cout <<"Descriptor " << _fds[i].fd << "is readable" << std::endl;
				read_request(_fds[i].fd);
			}
		}
	}

    return true;
}

void 		Server::read_request(int fd)
{
	int ret = _requests[fd].read_line(fd);

	if (ret == -1)
	{
		std::cout << "Connection closed" << std::endl;
		for (std::vector<pollfd>::iterator i = _fds.begin(); i != _fds.end(); ++i)
		{
			if (i->fd == fd)
				_fds.erase(i);
		}
	}
	if (ret == 1)
		_requests[fd].print_request_buffer();

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

}
