/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <sgath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 18:01:09 by sgath             #+#    #+#             */
/*   Updated: 2021/09/11 19:27:07 by sgath            ###   ########.fr       */
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

	//path
	std::string	m_pathCert;
	std::string	m_pathCertCA;
	std::string	m_pathKey;
	std::string	m_htmlData;

	//ssl_sert
	bool		initSSl( );
	bool		initSocket( );
	bool		settingClient( int, std::string );
	
public:

	Server( );
	Server( int aPort = 443 );
	Server( const Server &v );
	Server		operator=( Server &v );
	Server		operator=( const Server &v );
	~Server( );
	
	bool		startServ();
	
	//setters
	void		setCertPath( std::string path ); //ok
	void		setKeyPath( std::string path ); //ok
	void		setCAcertPath( std::string path ); //ok

	
};

#endif