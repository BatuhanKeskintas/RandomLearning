/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeskint <bkeskint@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 11:20:37 by bkeskint          #+#    #+#             */
/*   Updated: 2021/08/12 14:27:02 by bkeskint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char* argv[])
{
	int id = fork();
	int n;
	
	if (id == 0)
	{
		n = 1;
		printf("Waiting Process= %d \n", wait(NULL));
		sleep(1);
	}
	else
	{
		n = 6;
		printf("Process %d waiting ! \n", wait(NULL));
		sleep(1);
	}
	printf("Process ID: %d - Process: %d - Parent ID: %d \n", getpid(), id, getppid());
	for (int i = n; i < n + 5; i++ )
	{
		printf("%d ", i);
	}
	printf("\n");
	return (0);
}