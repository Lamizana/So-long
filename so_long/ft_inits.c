/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:13:36 by alamizan          #+#    #+#             */
/*   Updated: 2023/01/23 14:40:17 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	init_struct(t_map *map)
{
	map->tab = NULL;
	map->player = malloc(sizeof(t_image));
	map->wall = malloc(sizeof(t_image));
	map->door = malloc(sizeof(t_image));
	map->ground = malloc(sizeof(t_image));
	map->item = malloc(sizeof(t_image));
	if (!map->player || !map->wall || !map->door || !map->ground || !map->item)
	{
		free(map);
		exit (0);
	}
	map->player->count = 0;
	map->item->count = 0;
	map->ground->count = 0;
}

void	init_images(t_map *map)
{
	map->player->img = mlx_xpm_file_to_image(map->mlx, "./images/player.xpm",
			&map->player->img_x, &map->player->img_y);
	map->wall->img = mlx_xpm_file_to_image(map->mlx, "./images/wall_01.xpm",
			&map->wall->img_x, &map->wall->img_y);
	map->ground->img = mlx_xpm_file_to_image(map->mlx, "./images/ground_01.xpm",
			&map->ground->img_x, &map->ground->img_y);
	map->door->img = mlx_xpm_file_to_image(map->mlx, "./images/door.xpm",
			&map->door->img_x, &map->door->img_y);
	map->item->img = mlx_xpm_file_to_image(map->mlx, "./images/item_01.xpm",
			&map->item->img_x, &map->item->img_y);
}

void	init_map(t_map *map)
{
	map->mlx = mlx_init();
	if (map->mlx == NULL)
		exit(0);
	map->win = mlx_new_window(map->mlx, (map->len) * PIXEL,
			map->line * PIXEL, "So long");
	if (map->win == NULL)
	{
		free(map->win);
		exit (0);
	}
	init_images(map);
}
