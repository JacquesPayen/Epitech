/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** main
*/

#include "lib/GL/include/libGL.hpp"

int	main()
{
	libGraphic	*graph;

	void	*anything;
	libGraphic *(*create_lib)();

	anything = dlopen("./lib/lib_arcade_opengl.so", RTLD_LOCAL | RTLD_LAZY);
	if (!anything)
	{
     		fprintf(stderr, "%s\n", dlerror());
        	exit(EXIT_FAILURE);
	}
	create_lib = reinterpret_cast<libGraphic* (*)()>(dlsym(anything, "createLibGraph"));

	graph = create_lib();
	graph->clearW();
	graph->setCell(0, 0, 1);
	graph->refreshW();

	libGraphic	*graph;

	void	*anything;
	libGraphic *(*create_lib)();

	anything = dlopen("./lib/lib_arcade_opengl.so", RTLD_LOCAL | RTLD_LAZY);
	if (!anything)
	{
     		fprintf(stderr, "%s\n", dlerror());
        	exit(EXIT_FAILURE);
	}
	create_lib = reinterpret_cast<libGraphic* (*)()>(dlsym(anything, "createLibGraph"));


	


	while(1);
}