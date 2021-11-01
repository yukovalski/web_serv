/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgath <sgath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 20:20:51 by sgath             #+#    #+#             */
/*   Updated: 2021/09/12 14:37:32 by sgath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Webserv.hpp"

std::string     parsingConf(char *str)
{
    return str;
}

int		main()
{
	t_server	config;
	config.host = "127.0.0.1";
	config.port = 8080;
	Server		server(config);

	try
	{
		server.start();
	}
	catch (std::string exeption)
	{
		std::cout << "Error: " << exeption;
	}

//	std::string	confPath;
//
//	confPath = (argc == 1) ? "./conf/tester" : std::string(argv[1]);
//	try {
//        confPath = parsingConf(argv[1]);
//        std::cout << "u use " << confPath << std::endl;
//    }
//    catch (std::exception &e) {
//        std::cerr << "Error!" << std::endl;
//		std::cerr << " No valid config: " << e.what() << std::endl;
//        return (1);
//    }
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