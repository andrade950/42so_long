/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_messages.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:44:31 by joaomart          #+#    #+#             */
/*   Updated: 2025/03/11 21:55:42 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	info_message(char *msg)
{
	ft_printf("Info - %s\n", msg);
}

void	collect_message(int c)
{
	if (c > 1)
		ft_printf("Info - Ainda te faltam %i pilhas\n", c);
	if (c == 1)
		ft_printf("Info - Ja so te falta %i pilha\n", c);
	if (c == 0)
		ft_printf("Info - Ja apanhaste todas as pilhas podes terminas o mapa!\n");
}
