/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:12:37 by joaomart          #+#    #+#             */
/*   Updated: 2025/03/05 16:13:15 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	error(char *msg)
{
	ft_printf("Error - %s\n", msg);
	exit(EXIT_FAILURE);
}

void	error_fd(int fd, char *msg)
{
	ft_printf("Error - %s\n", msg);
	close(fd);
	exit(EXIT_FAILURE);
}
