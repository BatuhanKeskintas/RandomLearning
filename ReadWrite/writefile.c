/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writefile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeskint <bkeskint@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 12:44:07 by bkeskint          #+#    #+#             */
/*   Updated: 2021/08/13 13:30:41 by bkeskint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>


int	main(int argc, char* argv[])
{
	int	arr[5];
	srand(time(NULL));

	for(int i = 0; i < 5; i++)
	{
		arr[i] = rand() % 10;
		printf("Genrated %d \n", arr[i]);
	}
	int fd = open("file1", O_WRONLY);
	if (fd == -1)
		return (2);
	if (write(fd, arr, sizeof(int) * sizeof(arr)) == -1 )
		return (3);
	close(fd);
	
	return (0);
}