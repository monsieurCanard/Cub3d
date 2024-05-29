/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:12:44 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/29 11:34:53 by antgabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	print_error(char *message, int error)
{
	ft_putendl_fd("Error:", 2);
	ft_putendl_fd(message, 2);
	return (error);
}
