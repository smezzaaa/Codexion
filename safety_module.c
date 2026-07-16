/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safety_module.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 20:01:15 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/07/06 10:44:56 by smeza-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	*safe_malloc(long size)
{
	void	*tmp;
	tmp = malloc(size);
	if (!tmp)
		return(NULL);
	return tmp;
}