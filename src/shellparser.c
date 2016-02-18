/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shellparser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 03:34:46 by eleclet           #+#    #+#             */
/*   Updated: 2016/02/18 17:49:26 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"


int		argvparser(char **argv, char **param, t_lst *lst, t_lst *error)
{
	int i;
	int ret;

	i = 1;

	while (argv[i]) // parse parameter
	{
		if ((ret = parseargv(argv[i], param, &i)) == -1)
			return (1);
		if (ret == 0)
			break ;
			i++;
	}
	while (argv[i]) // parse file
	{
		getfileinfo(&lst, argv[i], &error);
		i++;
	}
	return (0);
}
int		parseargv(char *s, char **param, int *i)
{
	if (s[0] != '-')
		return (0);
	if (ft_strcmp(s, "--") == 0)
	{
		*i = *i + 1;
		return (0);
	}
	s++;
	*param = ft_strjoin(*param,s);
	while (*s)
	{
		if (*s != 'R' && *s != 'r' && *s != 'l' && *s != 'a' && *s != 't')
		{
			ft_putstr(ft_strjoin("ls: illegal option -- ", s));
			ft_putstr("\nusage: ls [-Raltr] [file ...]\n");
			return (-1);
		}
		s++;
	}
	return (1);
}

int		validfile(char *s)
{
	struct stat s_stat;

	if ((lstat(s, &s_stat) >= 0))
	{
		return (1);
	}
	ft_putstr("ls: ");
	ft_putstr(s);
	ft_putstr(": No such file or directory\n");
	return (0);
}

int controller(char **argv)
{
	char *param;
	t_lst *name;
	t_lst *error;

	error = init();
	name = init();
	param = NULL;
	if (argvparser(argv, &param, name, error) == 1)
	{
		ft_strdel(&param);
		return (0);
	}
	print(name->next);
	ft_putchar('\n');
	error_disp(error);
	sortfunc(param, &name);
	return (0);
}
int		main(int argc, char **argv)
{
	controller(argv);
	return (0);
}
