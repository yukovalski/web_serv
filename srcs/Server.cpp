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

Server::Server( ) :					m_port(80),
									m_socket(-1)
{}

Server::Server( int aPort ) :	    m_port(aPort),
									m_socket(-1)
{}

Server::Server( const Server &v ) :	m_port(v.m_port),
									m_socket(v.m_socket)
{}

Server&	Server::operator=( Server &v )
{
    if (&v != this){
        m_port = v.m_port;
        m_socket = v.m_socket;
    }
    return (*this);
}

Server&	Server::operator=( const Server &v )
{
	if (&v != this){
		m_port = v.m_port;
		m_socket = v.m_socket;
	}
	return (*this);
}

Server::~Server()
{}

bool	Server::startServ( )
{
    return true;
}
