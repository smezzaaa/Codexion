/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 18:50:25 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/07/08 15:21:34 by smeza-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static void	ft_free(t_quantum_compiler *qc)
{
	free(qc->coders);
	free(qc->dongles);
}

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

//controllo che i coders abbiano tutti accesso a due dongle?????
int	dongle_checker()
{
	return(0);
}

void	ft_cleanup(t_quantum_compiler *qc)
{
	int	i;
	t_dongle	*curr_dongle;
	
	i = 0;
	while (i <=qc->number_of_coders)
	{
		curr_dongle = qc->dongles + i;
		pthread_mutex_destroy(&curr_dongle->m);
		pthread_cond_destroy(&curr_dongle->c);
		i++;
	}
	pthread_mutex_destroy(&qc->gen_m);
	pthread_cond_destroy(&qc->gen_c);
	ft_free(qc);
	return ;
}
