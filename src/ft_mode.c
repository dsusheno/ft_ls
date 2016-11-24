/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 16:25:29 by dsusheno          #+#    #+#             */
/*   Updated: 2016/03/04 16:25:31 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_lib.h"

void	mode_2(char *mode, struct stat stat)
{
	if (stat.st_mode & S_IRGRP)
		mode[4] = 'r';
	if (stat.st_mode & S_IWGRP)
		mode[5] = 'w';
	if (stat.st_mode & S_IXGRP)
		mode[6] = 'x';
	if (stat.st_mode & S_ISGID)
	{
		if (mode[6] == 'x')
			mode[6] = 's';
		else
			mode[6] = 'S';
	}
	if (stat.st_mode & S_IROTH)
		mode[7] = 'r';
	if (stat.st_mode & S_IWOTH)
		mode[8] = 'w';
	if (stat.st_mode & S_IXOTH)
		mode[9] = 'x';
}

void	mode_1(char *mode, struct stat stat)
{
	if (S_ISDIR(stat.st_mode))
		mode[0] = 'd';
	if (S_ISCHR(stat.st_mode))
		mode[0] = 'c';
	if (S_ISBLK(stat.st_mode))
		mode[0] = 'b';
	if (S_ISLNK(stat.st_mode))
		mode[0] = 'l';
	if (S_ISSOCK(stat.st_mode))
		mode[0] = 's';
	if (S_ISFIFO(stat.st_mode))
		mode[0] = 'p';
	if (stat.st_mode & S_IRUSR)
		mode[1] = 'r';
	if (stat.st_mode & S_IWUSR)
		mode[2] = 'w';
	if (stat.st_mode & S_IXUSR)
		mode[3] = 'x';
	if (stat.st_mode & S_ISUID)
	{
		if (mode[3] == 'x')
			mode[3] = 's';
		else
			mode[3] = 'S';
	}
}

void	ft_mode(struct stat stat)
{
	char	*mode;

	mode = ft_strdup("----------  ");
	mode_1(mode, stat);
	mode_2(mode, stat);
	if (stat.st_mode & S_ISVTX)
	{
		if (mode[9] == 'x')
			mode[9] = 't';
		else
			mode[9] = 'T';
	}
	ft_putstr(mode);
	free(mode);
	mode = NULL;
}
