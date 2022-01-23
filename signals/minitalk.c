/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeskint <bkeskint@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 09:42:09 by bkeskint          #+#    #+#             */
/*   Updated: 2021/08/11 17:11:39 by bkeskint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	<stdio.h>
#include	<signal.h>
#include	<unistd.h>

void	handle_bigger(int sig)
{
	printf("PID is bigger than 3000!\n");
}

void	handle_smaller(int sig)
{
	printf("PId is smaller than 3000!\n");
}

int	main(int argc, char* argv[])
{
	int pid;
	pid = fork();
	struct sigaction sa;
	sa.sa_flags = SA_RESTART ;
	if (pid == -1)
		return (1);
	while (1)
	{
		if (pid == 0)
		{
			/*Child proccess*/
			sleep (5);
			kill(getppid(), SIGUSR1);
		}
		else
		{
			/*Parent Procces*/ 
			if (pid > 5000)
			{
				printf("PID: %d\n", pid);
				sa.sa_handler = &handle_bigger;
				sigaction(SIGUSR1, &sa, NULL);
			}
			else
			{
				printf("PID: %d\n", pid);
				sa.sa_handler = &handle_smaller;
				sigaction(SIGUSR1, &sa, NULL);
			}
			wait(NULL);
		}
	}
	return (0);
}