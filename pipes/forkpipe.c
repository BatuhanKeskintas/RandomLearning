/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forkpipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeskint <bkeskint@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:22:43 by bkeskint          #+#    #+#             */
/*   Updated: 2021/08/12 15:54:45 by bkeskint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <errno.h>

int	write_sum(int sum, int fd[])
{
	close(fd[0]);
	if (write(fd[1], &sum, sizeof(int)) == -1)
		return (2);
	close(fd[1]);
	return (0);
}

int	read_sum(int sum, int fd[])
{
	int sum_from_child;
	close(fd[1]);
	if (read(fd[0], &sum_from_child, sizeof(int)) == -1)
		return (3);
	close(fd[0]);
	sum += sum_from_child;
	printf("Total Sum = %d \n", sum);
	return (0);
}

int	main(int argc, char* argv[])
{
	int arr[] = {1, 2, 3, 4, 5 ,6, 7, 10};
	int size, st, end, id, sum;
	int fd[2];
	
	size = sizeof(arr) / sizeof(int);
	if (pipe(fd) == -1)
		return (1);
	id = fork();
	if (id == -1)
		return (2);
	if (id == 0)
	{
		st = 0;
		end = size / 2;
	}
	else
	{
		st = size / 2;
		end = size;
		wait(NULL);
	}
	sum = 0;
	for (int i = st; i < end; i++)
		sum += arr[i];
	printf("ID = %d -> Sum = %d \n", id, sum);
	if (id == 0)
	{
		if (write_sum(sum, fd) != 0)
			return (write_sum(sum, fd));
	}
	else
	{
		if (read_sum(sum, fd) != 0)
			return (read_sum(sum, fd));	
	}
	return (0);
}