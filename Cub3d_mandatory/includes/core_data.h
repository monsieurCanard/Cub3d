/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_data.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:08:52 by jbrousse          #+#    #+#             */
/*   Updated: 2024/06/05 12:29:08 by Monsieur_Ca      ###   ########.fr       */
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
	char		*texture[5];
	t_argb		floor;
	t_argb		ceiling;
	size_t		size_x;
	size_t		size_z;
	char		**map;
}	t_map;

#endif