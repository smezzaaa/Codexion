/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 17:09:42 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/07/08 15:19:31 by smeza-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static void	assign_dongle(t_quantum_compiler *qc)
{
	int			i;
	int			n;
	t_coder		*curr;

	i = 0;
	n = qc->number_of_coders;
	while (i < n)
	{
		curr = qc->coders + i;
		curr->r_dongle = qc->dongles + (i + 1);
		curr->l_dongle = qc->dongles + ((i + n - 1) % n);
		i++;
	}
}

void	dongle_initializer(t_quantum_compiler *qc)
{
	int	i;
	t_dongle *curr;

	i = 0;
	while (i < qc->number_of_coders)
	{
		curr = qc->dongles + i;
		pthread_mutex_init(&curr->m, NULL);
		pthread_cond_init(&curr->c, NULL);
		curr->last_release = 0;
		curr->taken = 0;
		i++;
	}
}

void	coder_initializer(t_quantum_compiler *qc)
{
	int	i;
	t_coder	*curr;

	i = 0;
	while (i < qc->number_of_coders)
	{
		curr = qc->coders + i;
		curr->id = i + 1;
		curr->last_compile = 0;
		curr->counter = 0;
		i++;
	}
	if (qc->number_of_coders == 1)
		curr->r_dongle = qc->dongles + 0;
	else
		assign_dongle(qc);
}

void	qc_initializer(t_quantum_compiler *qc,char **av)
{
	int	i;

	i = 0;
	qc->number_of_coders = atoi(av[1]);
	qc->time_to_burnout = atoi(av[2]);
	qc->time_to_compile = atoi(av[3]);
	qc->time_to_debug = atoi(av[4]);
	qc->time_to_refactor = atoi(av[5]);
	qc->number_of_compiles_required = atoi(av[6]);
	qc->dongle_cooldown = atoi(av[7]);
	qc->scheduler = av[8];
	qc->stop_flag = 0;
	qc->sim_time = 0;
	pthread_mutex_init(&qc->gen_m, NULL);
	pthread_cond_init(&qc->gen_c, NULL);
	qc->coders = safe_malloc(sizeof(t_coder)*qc->number_of_coders);
	qc->dongles = safe_malloc(sizeof(t_dongle)*(qc->number_of_coders));
	dongle_initializer(qc);
	coder_initializer(qc);
}
