/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <sgath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 19:14:59 by sgath             #+#    #+#             */
/*   Updated: 2021/09/11 19:33:21 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

Server::Server( ) :					m_port(443),
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

void	Server::setCertPath( std::string path )
{
	m_pathCert = path;
}

void	Server::setKeyPath( std::string path )
{
	m_pathKey = path;
}

void	Server::setCAcertPath( std::string path )
{
	m_pathCertCA = path;
}

bool	Server::startServ( )
{
	if (!Server::initSSl())
		exit(1);
	if (!Server::initSocket())
		exit(1);
	if (!Server::settingClient())
		exit(1);
}

bool	Server::initSSl( )
{
	
}

bool	Server::initSocket( )
{
	
}