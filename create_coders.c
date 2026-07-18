/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_coders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 18:39:29 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/07/18 18:59:09 by smeza-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	create_coders(t_quantum_compiler *qc)
{
	int	i;
	t_coder	*curr;
	pthread_t	t;

	i = 0;
	while(i < qc->number_of_coders)
	{
		curr = qc->coders + i;
		t = curr->t;
		pthread_create(&t, NULL, coder_routine, curr);
		i++;
	}
	i = 0;
	while(i < qc->number_of_coders)
	{
		curr = qc->coders + i;
		t = curr->t;
		pthread_join(&t, NULL);
		i++;
	}
}