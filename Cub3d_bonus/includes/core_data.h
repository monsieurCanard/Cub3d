/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_data.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:08:52 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/31 10:47:24 by antgabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_DATA_H
# define CORE_DATA_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

# define FAILURE -1
# define SUCCESS 0

enum e_texture
{
	NO,
	SO,
	WE,
	EA
};

typedef struct s_argb
{
	unsigned char	a;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	bool			is_set;
}	t_argb;

typedef struct s_map
{
	char		*texture[6];
	t_argb		floor;
	t_argb		ceiling;
	size_t		size_x;
	size_t		size_z;
	char		**map;
}	t_map;

#endif