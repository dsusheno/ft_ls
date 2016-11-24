/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 16:26:35 by dsusheno          #+#    #+#             */
/*   Updated: 2016/03/04 16:26:37 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_lib.h"

void	ft_non_r2(t_info *head, t_gen *flag)
{
	t_info			*tmp2;
	t_info			*tmp;

	if (flag->n_argc > 2)
	{
		ft_putstr(head->name);
		ft_putstr(":\n");
	}
	tmp = ft_tri(head->name, flag);
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2->name);
		free(tmp2);
		tmp2 = NULL;
	}
}

void	ft_non_r(t_gen *flag)
{
	t_info			*head;
	t_info			*tmp;
	int				x;

	x = 0;
	head = flag->head;
	while (head)
	{
		if (S_ISDIR(head->mode) || head->is_link == 1)
			ft_non_r2(head, flag);
		if (head && S_ISDIR(head->mode) &&
			head->next && S_ISDIR(head->next->mode))
			ft_putchar('\n');
		tmp = head;
		head = head->next;
		free(tmp->name);
		free(tmp);
	}
}

void	ft_check_arg(int argc, char **argv, char *tab, t_gen *flag)
{
	t_app			ap;

	ap.nb_app_n = 0;
	ap.nb_app = 0;
	if (argc < 2)
		ft_tri(".", flag);
	else if (flag->rr == 1)
	{
		if (!argv[flag->i] || !ft_strcmp(argv[flag->i], "."))
			ft_br(tab, flag, &ap);
		else if ((flag->head = multi_arg(argv, flag)))
			ft_read_br(tab, flag, &ap);
	}
	else
	{
		if (!argv[flag->i])
			ft_tri(".", flag);
		else
		{
			flag->head = multi_arg(argv, flag);
			ft_non_r(flag);
		}
	}
}

int		main(int argc, char **argv)
{
	char	*tab;
	t_gen	*flag;
	int		x;

	x = 1;
	flag = malloc(sizeof(t_gen));
	flag->i = 1;
	tab = (char *)malloc(sizeof(char) * 2);
	flag->n_argc = argc;
	if (ft_flag(argv, flag, x) == 1)
	{
		ft_putstr_fd("ft_ls: illegal option -- ", 2);
		ft_putstr_fd(&(flag->symb), 2);
		ft_putstr_fd("\nusage: ft_ls [-TRaflrt] [file ...]\n", 2);
		return (0);
	}
	ft_check_arg(argc, argv, tab, flag);
	return (0);
}
