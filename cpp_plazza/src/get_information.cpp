/*
** EPITECH PROJECT, 2018
** .
** File description:
** .
*/

#include "../include/my.h"

int	createConnection(SOCKET *s)
{
	int 			fd;
	struct protoent		*protocol;
	
	protocol = getprotobyname("TCP"); 
	if (protocol == NULL)
		return -1;
	s->setPe(protocol);
	fd = socket(AF_INET, SOCK_STREAM, protocol->p_proto);
	s->setFd(fd);
	return 0;
}

int	myConnect(SOCKET *s)
{
	struct sockaddr_in	addr;

	addr.sin_family = AF_INET;
	addr.sin_port = htons(s->getPort());
	addr.sin_addr.s_addr = inet_addr("0");
	s->setSin(addr);
	connect(s->getFd(), (struct sockaddr *)&addr, sizeof(addr));
	return 0;
}

std::vector<std::string>	buildCommand(char *str)
{
	std::istringstream		msg((std::string) str);
	std::string			ins;
	std::vector<std::string>	vect;
	
	while (std::getline(msg, ins, ';')) {
		vect.insert(vect.begin(), ins);
	}	
	return	vect;
}

int	pushInstruction(char *str, ARGUMENT *parametre)
{
	std::vector<std::string>	list;
	int				size = 1;

	list = buildCommand(str);
	parametre->lock();
	parametre->set_instruction(list);
	parametre->unlock();
	while (size != 0) {
		list =  parametre->get_vector();
		size = list.size();
	}
	return (0);
}

int	slave(int port, int nb_tread)
{
	SOCKET		s;
	int		nb;
	char		buf[128];
	ARGUMENT	parametre;
	pthread_t	th[nb_tread];

	s.setPort(port);
	createConnection(&s);
	myConnect(&s);
	parametre.set_arguments();
	for (int i = 0; i < nb_tread; i += 1) {
		pthread_create(&th[i], NULL, thMain, (void *) &parametre);
	}
	while(1) {
		memset(buf, 0, 128);
		nb = 0;
		while (nb < 1)
			nb = read(s.getFd(), buf, 128);
		pushInstruction(buf, &parametre);
		write(s.getFd(), "ok\n", 3);
	}
	return 0;
}
