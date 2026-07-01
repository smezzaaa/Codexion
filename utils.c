/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 18:50:25 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/07/01 20:07:05 by smeza-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void *input_checker(char **av)
{
	int i;

	i = 1;
	while (av[i])
	{
		if (i == 8)
		{
			if ((strcmp(av[i], "fifo") != 0) && (strcmp(av[i], "edf") != 0))
				return NULL;
		}
		else
		{
			if (strcmp(av[i], "0") == 0)
				return NULL;
			else if (atoi(av[i]) <= 0)
				return NULL;
		}

		i++;
	}
	return("ciao");
}
