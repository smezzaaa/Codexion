/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 19:19:15 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/07/08 16:10:56 by smeza-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int main(int ac, char **av)
{
    if (ac != 9)
        return(write(1, "[ERROR] Invalid Number of Arguments\n", 37));
    if (!input_checker(av))
		return(write(1, "[WARNING] Invalid Input!\n", 26));
	t_quantum_compiler	qc;
	pthread_t	monitor;

	qc_initializer(&qc, av);
	if (qc.number_of_coders == 1)
	{
		pthread_create(&monitor, NULL, one_coder_monitor, &qc);
		pthread_join(monitor, NULL);
	}
	else
	{
		pthread_create(&monitor, NULL, coder_monitor, &qc);
		pthread_join(monitor, NULL);
	}
	
}