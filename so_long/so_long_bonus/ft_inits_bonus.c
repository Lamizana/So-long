/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inits_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:13:36 by alamizan          #+#    #+#             */
/*   Updated: 2023/01/23 14:39:43 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	line_counter(t_map *map)
{
	char	*ret;

	ret = get_next_line(map->fd);
	if (ret == 0)
		ft_error(map, 3);
	map->len = ft_strlen(ret);
	while (ret != NULL)
	{
		free(ret);
		map->line++;
		ret = get_next_line(map->fd);
		if (ret == NULL)
			free(ret);
	}
}

void	open_file(int argc, char *argv[], t_map *map)
{
	int		i;
	char	**tmp;

	tmp = NULL;
	check_arg(argc, argv, map);
	i = 0;
	map->line = 0;
	map->len = 0;
	map->fd = open(argv[1], O_RDONLY);
	if (map->fd == -1)
		ft_error(map, 3);
	line_counter(map);
	map->tab = malloc(sizeof(char *) * (map->line));
	close(map->fd);
	map->fd = open(argv[1], O_RDONLY);
	while (i < map->line)
		map->tab[i++] = get_next_line(map->fd);
	get_next_line(map->fd);
	close(map->fd);
	parse_door_player(map);
	parse_wall(map);
	parse_item(map);
	tmp = duplicate_map(map);
	check_start(tmp, map);
}

void	init_struct(t_map *map)
{
	map->tab = NULL;
	map->player = malloc(sizeof(t_image));
	map->player_l = malloc(sizeof(t_image));
	map->enemy = malloc(sizeof(t_image));
	map->wall = malloc(sizeof(t_image));
	map->door = malloc(sizeof(t_image));
	map->ground = malloc(sizeof(t_image));
	map->item = malloc(sizeof(t_image));
	map->item_02 = malloc(sizeof(t_image));
	map->item_03 = malloc(sizeof(t_image));
	if (!map->player || !map->wall || !map->door || !map->ground || !map->item)
	{
		free(map);
		exit (0);
	}
	map->player->count = 0;
	map->item->count = 0;
	map->item_02->count = 0;
	map->ground->count = 0;
}

void	init_images(t_map *map)
{
	map->player->img = mlx_xpm_file_to_image(map->mlx, "./images/player_02.xpm",
			&map->player->img_x, &map->player->img_y);
	map->player_l->img = mlx_xpm_file_to_image(map->mlx,
			"./images/player_02_l.xpm", &map->player_l->img_x,
			&map->player_l->img_y);
	map->enemy->img = mlx_xpm_file_to_image(map->mlx, "./images/slime.xpm",
			&map->enemy->img_x, &map->enemy->img_y);
	map->wall->img = mlx_xpm_file_to_image(map->mlx, "./images/wall_01.xpm",
			&map->wall->img_x, &map->wall->img_y);
	map->ground->img = mlx_xpm_file_to_image(map->mlx, "./images/ground_02.xpm",
			&map->ground->img_x, &map->ground->img_y);
	map->door->img = mlx_xpm_file_to_image(map->mlx, "./images/door_01.xpm",
			&map->door->img_x, &map->door->img_y);
	map->item->img = mlx_xpm_file_to_image(map->mlx, "./images/item_02.xpm",
			&map->item->img_x, &map->item->img_y);
	map->item_02->img = mlx_xpm_file_to_image(map->mlx, "./images/item_03.xpm",
			&map->item_02->img_x, &map->item_02->img_y);
	map->item_03->img = mlx_xpm_file_to_image(map->mlx, "./images/item_04.xpm",
			&map->item_03->img_x, &map->item_03->img_y);
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
