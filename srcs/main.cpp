/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu <yu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 20:20:51 by sgath             #+#    #+#             */
/*   Updated: 2021/09/11 23:35:12 by yu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/webserv.hpp"

int		main(int argc, char **argv)
{
	std::string	confPath;

	confPath = (argc == 1) ? "./conf/test" : std::string(argv[1]);
	
	//pars config file
		//check path
		//get_next_line
			//add server
			//if server_clacc no valid - close fd and return 1
				//write error
	//if server running
	//signal proggressing
	//webserv(conf)
	//closes fd
	return 0;
}