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

#include "../includes/webserv.hpp"

class			Server
{
private:
	int			m_socket;
	int			m_port;

	std::string	m_htmlData;

	bool		settingClient( int, std::string );
	
public:

	Server( );
	Server( int aPort = 80 );
	Server( const Server &v );
	Server		operator=( Server &v );
	Server		operator=( const Server &v );
	~Server( );
	
	bool		startServ();

	
};

#endif