/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 12:13:13 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/07/16 18:09:33 by smeza-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

// aggiungere gettimeofday per controllo del bornout/cercare alternativa

static void	*solo_coder_routine(void *arg)
{
	int					start;
	int					end;
	t_quantum_compiler	*qc;
	t_coder				*coder;
	struct timeval		tv;

	if (gettimeofday(&tv, NULL) != 0)
		return NULL;
	start = tv.tv_usec;
	qc = (t_quantum_compiler *)(arg);
	coder = qc->coders + 0;
	if (usleep((qc->time_to_burnout) * 1000) != 0)
		return NULL;
	if (gettimeofday(&tv, NULL) != 0)
		return NULL;
	end = tv.tv_usec;
	if (((end - start) * 1000) >= qc->time_to_burnout)
	{
		qc->stop_flag = -1;
		printf("%d %d burned out\n", ((end - start) / 1000), coder->id);
	}
	return NULL;
}

void	*one_coder_monitor(void *arg)
{
	t_coder *coder;
	t_quantum_compiler *qc;

	qc = (t_quantum_compiler *)(arg);
	coder = qc->coders + 0;
	pthread_create(&coder->t, NULL, solo_coder_routine, qc);
	pthread_join(coder->t, NULL);
	ft_cleanup(qc);
	return (NULL);
}