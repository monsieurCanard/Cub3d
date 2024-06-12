/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:38:25 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/11 15:39:13 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_findstr(char *str, char *to_find, int index)
{
	int		j;

	j = 0;
	while (str[index] != '\0')
	{
		if (to_find != NULL && str[index] == to_find[j])
		{
			while (str[index + j] == to_find[j]
				&& to_find[j] != '\0')
			{
				j++;
			}
			if (to_find[j] == '\0')
				return (index);
			j = 0;
		}
		index++;
	}
	return (-1);
}
