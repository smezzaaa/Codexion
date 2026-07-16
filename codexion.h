/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 18:47:24 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/07/08 16:11:15 by smeza-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
#define CODEXION_H

#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

typedef struct heap
{
	int	*arr;
	int		size;
	int		capacity;
}	heap;

typedef struct s_dongle
{
	pthread_mutex_t	m; // per proteggere l'esecuzione
	pthread_cond_t	c; // per proteggere l'esecuzione
	int 			last_release; // per monitorare cooldown
	heap			priority_queue;
	int				taken;
}	t_dongle;

typedef struct s_coder
{
	int	id;
	int last_compile; // per monitorare burnout (se aspetta per troppo tempo)
	int counter; // conta quante volte ha compilato
	t_dongle	*l_dongle;
	t_dongle	*r_dongle;
	pthread_t	t;
}	t_coder;

typedef struct s_quantum_compiler
{
	int				number_of_coders;
	int				time_to_compile;
	int				time_to_burnout;
	int				time_to_debug;
	int				time_to_refactor;
	int				number_of_compiles_required;
	int 			dongle_cooldown;
	char			*scheduler;
	int				stop_flag;
	t_coder			*coders;
	t_dongle		*dongles;
	int				sim_time;
	pthread_mutex_t	gen_m;
	pthread_cond_t	gen_c;
}	t_quantum_compiler;

void	*input_checker(char **av);
void	*safe_malloc(long size);
int		main(int ac, char **av);
void	qc_initializer(t_quantum_compiler *qc, char **av);
void	dongle_initializer(t_quantum_compiler *qc);
void	coder_initializer(t_quantum_compiler *qc);
void	ft_cleanup(t_quantum_compiler *qc);
void	*one_coder_monitor(void *arg);
void	*coder_monitor(void *arg);


#endif