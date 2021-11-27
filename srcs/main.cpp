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

int		main(int ac, char **av)
{
	std::vector<t_server>	config;

	try
	{
		config = parse_config(ac, av);
		Server	server(config);

		server.start();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}