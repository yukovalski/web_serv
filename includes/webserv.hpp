/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   webserv.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <sgath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 18:18:16 by sgath             #+#    #+#             */
/*   Updated: 2021/09/12 14:33:53 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HPP
#define WEBSERV_HPP

#include <iostream>
#include <string>
#include <list>
#include <signal.h>
#include <sys/socket.h>

//class
#include "../srcs/Server.hpp"

// Colors
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define RESET "\033

//std::exception
class	NoValidConf : public std::exception
{
	virtual const char*	what( ) const throw();
};



#endif