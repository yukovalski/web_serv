//
// Created by Sergey Uryashev on 16.11.2021.
//

#include "Webserv.hpp"

int 	create_socket(const std::string& host, int port)
{
	int 	fd, ret, on = 1;

	std::cout << "creating socket on " << host << ":" << port << std::endl;
	fd = socket(AF_INET, SOCK_STREAM, 0);
	if (fd < 0)
		return puterror("can't create socket", errno);
	ret  = setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
	if  (ret == -1)
		return puterror("setsockopt failed", errno);

	return 0;
}

std::map<int, std::pair<std::string, int> >
        create_listening_sockets(const std::vector<t_server>& config)
{
	std::set<std::pair<std::string, int> >		hostports;
	std::map<int, std::pair<std::string, int> >	res;
	int 										fd;

	for (size_t i = 0; i < config.size(); ++i)
		hostports.insert(std::pair<std::string, int>(config[i].host,
													 config[i].port));
	std::set<std::pair<std::string, int> >::iterator	i = hostports.begin();
	for (;i != hostports.end(); ++i)
	{
		fd = create_socket(i->first, i->second);
		res[fd] = *i;
	}
	return res;
};
