/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pedantic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeskint <bkeskint@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:44:55 by bkeskint          #+#    #+#             */
/*   Updated: 2022/01/24 21:09:29 by bkeskint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int	main(int argc, char *argv[])
{
	int		fds[2];										//an array that will hold 2 file descriptors
	pipe(fds);											//populates fds with 2 file descriptors
	pid_t	pid = fork();								//create child process that is a clone of the parent

	if (pid == 0)										//"0" is for child process
	{
		dup2(fds[0], STDIN_FILENO);						//fds[0] (the read end of pipe) donates its data to file descriptor 0
		close(fds[0]);									//file descriptor no longer needs in the child since stdin is a copy
		close(fds[1]);									//file descriptor unused in child
		char	*argv[] = {(char *)"sort", NULL}; 		//create argument vector
		if (execvp(argv[0], argv)< 0)					//run sort command - exit if something wrong
			exit(0);
	}													//after this point we are moving with parent process
	close(fds[0]);										//file descriptor unused in parent
	const char	*words[] = {"pear", "peach", "apple"};	//write input to the writable file descriptor so it can be read in from child:
	size_t	numwords = sizeof(words)/sizeof(words[0]);
	for (size_t i = 0; i < numwords; i++)
		dprintf(fds[1], "%s\n", words[i]);
	close(fds[1]);										//send EOF so child can continue (child blocks untill all inputs has been processed)
	int		status;
	pid_t	wpid = waitpid(pid, &status, 0);			//wait for child to finish before exiting
	return	wpid == pid && WIFEXITED(status) ? WEXITSTATUS(status) : -1;
}