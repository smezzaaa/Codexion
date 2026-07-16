/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 14:51:43 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/07/16 18:21:44 by smeza-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	dongle_cooldown(int cooldown)
{
	if (usleep((cooldown) * 1000) != 0)
		return;
}

int	gettime()
{
	struct timeval		tv;
	if (gettimeofday(&tv, NULL) != 0)
		return (-1);
	return(tv.tv_usec);
}

heap	*update_pq(t_coder cod, t_quantum_compiler qc)
{
	
}

static void	*coder_routine(void *arg)
{
	int	start;
	int	end;
	int	lap;
	t_coder *coder; //devo passargli il coder preciso dalla priority queue!!!
	t_quantum_compiler	*qc;

	lap = 0;
	qc = (t_quantum_compiler *)(arg);
	while(coder->counter <= qc->number_of_compiles_required)
	{
		pthread_mutex_lock(&coder->r_dongle->m);
		start = gettime();
		if (start < 0)
			return NULL;
		printf("%d %d is compiling\n", coder->last_compile, coder->id);
		if (usleep((qc->time_to_compile) * 1000) != 0)
			return NULL;
		end = gettime();
		if (end < 0)
			return NULL;
		lap += (end - start) * 1000;
		printf("%d %d is debugging\n", lap, coder->id);
		if (usleep((qc->time_to_debug) * 1000) != 0)
			return NULL;
				end = gettime();
		if (end < 0)
			return NULL;
		lap += (end - start) * 1000;
		printf("%d %d is refactoring\n", lap, coder->id);
		if (usleep((qc->time_to_refactor) * 1000) != 0)
			return NULL;
		if (end < 0)
			return NULL;
		lap += (end - start) * 1000;
		coder->last_compile = lap;
		coder->counter += 1;
		if (coder->last_compile >= qc->time_to_burnout)
		{
			qc->stop_flag = -1;
			printf("%d %d burned out\n", lap, coder->id);
			break;
		}
		pthread_mutex_unlock(&coder->r_dongle->m);
		dongle_cooldown(qc->dongle_cooldown);
	}
	return (NULL);
}

void	*coder_monitor(void *arg)
{
	int	i;
	t_coder *coder;
	t_quantum_compiler *qc;

	i = 0;
	qc = (t_quantum_compiler *)(arg);
	while (i < qc->number_of_coders)
	{
		coder = qc->coders + i;
		pthread_create(&coder->t, NULL, coder_routine, qc);
		pthread_join(coder->t, NULL);
		i++;
	}
	ft_cleanup(qc);
	return (NULL);
}