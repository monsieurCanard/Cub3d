/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:47:42 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/02 19:32:25 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_copy_tab(char **tab, int start, int end)
{
	int		i;
	char	**new_tab;

	i = 0;
	new_tab = ft_calloc(end - start + 1, sizeof(char *));
	while (start != end)
	{
		new_tab[i] = ft_strdup(tab[start]);
		if (new_tab[i] == NULL)
			return (NULL);
		start++;
		i++;
	}
	new_tab[i] = NULL;
	return (new_tab);
}
