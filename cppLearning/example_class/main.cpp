/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeskint <bkeskint@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:49:42 by bkeskint          #+#    #+#             */
/*   Updated: 2022/04/11 22:48:06 by bkeskint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dlfcn.h>
#include "entity.hpp"
#include "player.hpp"

void	dlerror_wrapper()
{
	std::cerr << "Error: " << dlerror() << std::endl;
	exit(EXIT_FAILURE);
}

int main(int ac, char **av)
{
	void		*dl_handle;
	entity		*(*PlayerCreator)(std::string);
	entity		*newPlayer;
	entity		*secondPlayer;
	void		(*PlayerDestructor)(entity*);

	dl_handle = dlopen(av[1], RTLD_LAZY | RTLD_LOCAL);
	if (!dl_handle)
		dlerror_wrapper();
	
	PlayerCreator = (entity *(*)(std::string)) dlsym(dl_handle, "createPlayer");
	if (!PlayerCreator)
		dlerror_wrapper();
	
	newPlayer = PlayerCreator("Conan");
	secondPlayer = PlayerCreator("Pikachu");
	std::cout << "Conan Score: " << newPlayer->getScore() << std::endl << "Pikachu Score: " << secondPlayer->getScore() << std::endl;
	newPlayer->announces();
	secondPlayer->announces();
	newPlayer->markPoint();
	secondPlayer->markPoint();
	secondPlayer->markPoint();
	newPlayer->announces();
	secondPlayer->announces();
	std::cout << "Conan Score: " << newPlayer->getScore() << std::endl << "Pikachu Score: " << secondPlayer->getScore() << std::endl;
	
	PlayerDestructor = (void(*)(entity*))dlsym(dl_handle, "deletePlayer");
	if (!PlayerDestructor)
		dlerror_wrapper();
	
	PlayerDestructor(newPlayer);
	PlayerDestructor(secondPlayer);
	
	dlclose(dl_handle);
	
	return (0);
}