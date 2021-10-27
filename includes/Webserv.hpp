/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   webserv.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <sgath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 18:18:16 by sgath             #+#    #+#             */
/*   Updated: 2021/09/12 15:21:02 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HPP
#define WEBSERV_HPP

#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <vector>
#include <map>
#include <signal.h>
#include <sys/socket.h>

//class
#include "Server.hpp"
#include "Location.hpp"

// Colors
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define RESET "\033[34m"

//std::exception
class		NoValidConf : public std::exception
{
	virtual const char*	what( ) const throw( );
};

//pars
std::string	parsingConf( std::string path );


#endif