/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:07:06 by anthony           #+#    #+#             */
/*   Updated: 2024/05/17 15:17:28 by antgabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"

static int	take_texture_img(char **file_name, t_img **texture_tab)
{
	t_img	*texture_img;
	int		i;
	int		height;
	int		width;

	i = 0;
	while (i < 4)
	{
		texture_img = malloc(sizeof(t_img));
		texture_img->img_ptr = mlx_xpm_file_to_image(get_engine()->mlx,
				file_name[i], &width, &height);
		printf("File name = %s\n", file_name[i]);
		if (texture_img->img_ptr == NULL)
		{
			perror("Error\n");
			return (FAILURE);
		}
		texture_img->addr = mlx_get_data_addr(texture_img->img_ptr,
				&(texture_img->bpp), &(texture_img->l_length),
				(&texture_img->endian));
		printf("texture_img->addr = %p\n", texture_img->addr);
		if (texture_img->addr == NULL)
		{
			perror("Error\n");
			return (FAILURE);
		}
		texture_img->size = vector2(width, height);
		texture_tab[i] = texture_img;
		i++;
	}
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_engine	*engine;
	t_data		data;

	engine = get_engine();
	if (ac != 2)
	{
		errno = EINVAL;
		perror("Error\n");
		exit(FAILURE);
	}
	data.map_data = get_map(av[1]);
	if (data.map_data == NULL)
	{
		perror("Error\n");
		exit(FAILURE);
	}
	if (init_engine() == FAILURE)
		return (EXIT_FAILURE);
	if (init_window(vector2(800, 800), "Cub2d") == FAILURE)
		return (EXIT_FAILURE);
	if (init_window(vector2(1080, 1080), "Cub3d") == FAILURE)
		return (EXIT_FAILURE);
	if (take_texture_img(data.map_data->texture, data.texture_img) == FAILURE)
		return (EXIT_FAILURE);
	start_game(&data);
	return (0);
}
