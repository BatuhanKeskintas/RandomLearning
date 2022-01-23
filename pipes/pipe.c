/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeskint <bkeskint@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 14:56:47 by bkeskint          #+#    #+#             */
/*   Updated: 2021/08/12 15:12:17 by bkeskint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <errno.h>

int	main(int argc, char* argv[])
{
	int fd[2];
	int id;
	
	if (pipe(fd) == -1)
	{
		printf("An error occured while opening the pipe!");
		return (1);
	}
	id = fork();
	if (id == -1)
	{
		printf("An error occured whit fork!");
		return (4);
	}
	if (id == 0)
	{
		close(fd[0]);
		if (write(fd[1], &id, sizeof(int)) == -1)
		{
			printf("An error occured while writing to the file!");
			return (2);
		}
		close(fd[1]);
	}
	else
	{
		int x;
		close(fd[1]);
		if (read(fd[0], &x, sizeof(int)) == -1)
		{
			printf("An error occured while reading from the file!");
			return (3);
		}
		close(fd[0]);
		printf("Read from Child process(id): %d \n", x);
	}
	return (0);
}