/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 16:26:07 by dsusheno          #+#    #+#             */
/*   Updated: 2016/03/04 16:26:10 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_lib.h"

void	ft_time_2(long int st, char *s1, char *s2, char *tmp)
{
	time_t	t;
	char	*s3;

	if (time(&t) - st >= 15552000 || st - time(&t) > 0)
	{
		s3 = ft_strrchr(tmp, ' ');
		*s3 = '\0';
	}
	ft_putstr(s1);
	if (time(&t) - st >= 15552000 || st - time(&t) > 0)
	{
		s2++;
		s2 = ft_strrchr(s2, ' ');
		s2++;
		s3 = ft_strrchr(s2, '\n');
		*s3 = '\0';
		ft_sp_str(2, s2++, 0, 0);
	}
}

void	ft_time(long int st, t_gen *flag)
{
	char	*tmp;
	char	*s1;
	char	*s2;
	time_t	t;

	if (!(tmp = ctime(&(st))))
	{
		perror("Error: ");
		return ;
	}
	s1 = ft_strchr(tmp, ' ');
	if (flag->tt == 1)
		s2 = ft_strrchr(tmp, '\n');
	else
		s2 = ft_strrchr(tmp, ':');
	*s2 = '\0';
	if ((time(&t) - st >= 15552000 || st - time(&t) > 0) && flag->tt != 1)
		ft_time_2(st, s1, s2, tmp);
	else
		ft_putstr(s1);
	ft_putchar(' ');
}
