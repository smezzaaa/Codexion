/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:14:00 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/07/18 19:29:34 by smeza-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	*coder_routine(void *arg)
{
	t_coder	*coder;
	t_dongle	*r_d;
	t_dongle	*l_d;

	coder = (t_coder *)(arg);
	r_d = coder->r_dongle;
	l_d = coder->l_dongle;
	pthread_mutex_lock(&coder->r_dongle);
	while (coder->heap_pos != 1) // aggiungere un'altra heap pos sia per sinistro che per destro
	{
		send_request(coder);
		pthread_cond_wait(r_dongle->c)
	}
		
	
}