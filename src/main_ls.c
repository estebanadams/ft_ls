/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 13:15:25 by eleclet           #+#    #+#             */
/*   Updated: 2016/02/10 14:59:20 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

main_ls(*param)
{
	if (!ft_strchr('R', param))
	{
		return (0);
	}
	else
	{


		if (ft_strchr('l', param))
			printlist();
	}
}
