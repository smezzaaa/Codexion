/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 19:19:15 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/07/01 19:51:56 by smeza-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int main(int ac, char **av)
{
    if (ac != 9)
        return(write(1, "[ERROR]\n", 8));
    if (!input_checker(av))
		return(write(1, "[WARNING] Invalid Input!\n", 26));
	else
		printf("alright!");
}