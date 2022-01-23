/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeskint <bkeskint@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 12:44:09 by bkeskint          #+#    #+#             */
/*   Updated: 2021/08/13 13:34:13 by bkeskint         ###   ########.fr       */
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
	int sum;
	int fd = open("file1", O_RDONLY);
	if (fd == -1)
		return (1);
		if (read(fd, arr, sizeof(int) * 5) == -1)
			return (2);
	close(fd);
	for (int i = 0; i < 5; i ++)
		sum += arr[i];
	printf ("Sum: %d \n", sum);

	return (0);
}