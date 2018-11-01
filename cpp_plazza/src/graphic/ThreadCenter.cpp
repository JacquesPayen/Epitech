/*
** EPITECH PROJECT, 2018
** .
** File description:
** .
*/

#include "../../include/my.h"

std::string	getTask(ARGUMENT *arg)
{
	std::vector<std::string>	list;
	std::string			task ("");

	arg->lock();
	list = arg->get_vector();
	if (list.empty() == false) {
		task = list.back();
		list.pop_back();
		arg->set_instruction(list);
	}	
	arg->unlock();
	return task;
}

void	printList(std::vector<std::string> list, ARGUMENT *arg)
{
	std::ofstream logfile;

	logfile.open("log.txt", std::ofstream::app);
	arg->lockFile();
	for (int i = 0; i < list.size(); i += 1)
		logfile << list[i] << std::endl;
	logfile.close();
	arg->unlockFile();
}

void	*thMain(void *param)
{
	ARGUMENT			*arg = (ARGUMENT *) param;
	std::string			task ("");
	std::string			file;
	std::vector<std::string>	list;
	int				len;

	while (1) {
		if ((task = getTask(arg)) != "") {
			len = 0;
			for (int i = 0; task[i] != ' '; i += 1)
				len += 1;
			file.assign(task, 0, len);
			task.assign(task, len + 1, task.size() - len);
			list = search(file, task);
			printList(list, arg);
		}
	}
}
