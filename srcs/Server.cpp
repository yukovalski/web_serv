/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu <yu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 19:14:59 by sgath             #+#    #+#             */
/*   Updated: 2021/09/11 23:11:20 by yu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

Server::Server( ) :					m_port(80),
									m_socket(-1)
{}

Server::Server( int aPort = 443 ) :	m_port(aPort),
									m_socket(-1)
{}

Server::Server( const Server &v ) :	m_port(v.m_port),
									m_socket(v.m_socket)
{}

Server	Server::operator=( Server &v )
{}

Server	Server::operator=( const Server &v )
{}

Server::~Server()
{}

bool	Server::startServ( )
{

}
