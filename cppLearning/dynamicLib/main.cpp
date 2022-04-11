/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeskint <bkeskint@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:56:28 by bkeskint          #+#    #+#             */
/*   Updated: 2022/04/11 21:09:40 by bkeskint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dlfcn.h>
#include <iostream>

void	dlerror_wrapper()
{
	std::cerr << "Error: " << dlerror() << std::endl;
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	void	*dl_handle;
	int		(*square_ptr)(int);

	dl_handle = dlopen(av[1], RTLD_LAZY | RTLD_LOCAL);
	square_ptr = (int(*)(int)) dlsym(dl_handle, "square");
	if (!square_ptr)
		dlerror_wrapper();

	std::cout << "3 * 3 = " << square_ptr(3) << std::endl;
	dlclose(dl_handle);
	return (0);
}