/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:34:22 by alamizan          #+#    #+#             */
/*   Updated: 2023/01/23 08:23:20 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	handle_key(int key, t_map *map)
{
	if (key == XK_Escape)
		ft_close(map);
	move_up(key, map);
	move_down(key, map);
	move_right(key, map);
	move_left(key, map);
	display_counter(map);
	return (0);
}

void	event_up(t_map *map, int i, int j)
{
	if (map->tab[i - 1][j] == 'C')
		map->item->count += 1;
	else if (map->tab[i - 1][j] == 'E')
	{
		if (map->ground->count == map->item->count)
			ft_close(map);
		else
			return ;
	}
	map->tab[i - 1][j] = 'P';
	map->tab[i][j] = '0';
	mlx_put_image_to_window(map->mlx, map->win,
		map->ground->img, j * 64, i * 64);
	mlx_put_image_to_window(map->mlx, map->win,
		map->player->img, j * 64, (i -1) * 64);
	map->player->count += 1;
	return ;
}

void	event_down(t_map *map, int i, int j)
{
	if (map->tab[i + 1][j] == 'C')
		map->item->count += 1;
	else if (map->tab[i + 1][j] == 'E')
	{
		if (map->ground->count == map->item->count)
			ft_close(map);
		else
			return ;
	}
	map->tab[i + 1][j] = 'P';
	map->tab[i][j] = '0';
	mlx_put_image_to_window(map->mlx, map->win,
		map->ground->img, j * 64, i * 64);
	mlx_put_image_to_window(map->mlx, map->win,
		map->player->img, j * 64, (i + 1) * 64);
	map->player->count += 1;
	if (map->tab[i + 1][j] == 'E')
	{
		if (map->ground->count == map->item->count)
			ft_close(map);
		else
			return ;
	}
	return ;
}

void	event_right(t_map *map, int i, int j)
{
	if (map->tab[i][j + 1] == 'C')
		map->item->count += 1;
	else if (map->tab[i][j + 1] == 'E')
	{
		if (map->ground->count == map->item->count)
			ft_close(map);
		else
			return ;
	}
	map->tab[i][j + 1] = 'P';
	map->tab[i][j] = '0';
	mlx_put_image_to_window(map->mlx, map->win,
		map->ground->img, j * 64, i * 64);
	mlx_put_image_to_window(map->mlx, map->win,
		map->player->img, (j + 1) * 64, i * 64);
	map->player->count += 1;
}

void	event_left(t_map *map, int i, int j)
{
	if (map->tab[i][j - 1] == 'C')
		map->item->count += 1;
	else if (map->tab[i][j - 1] == 'E')
	{	
		if (map->ground->count == map->item->count)
			ft_close(map);
		else
			return ;
	}
	map->tab[i][j - 1] = 'P';
	map->tab[i][j] = '0';
	mlx_put_image_to_window(map->mlx, map->win,
		map->ground->img, j * 64, i * 64);
	mlx_put_image_to_window(map->mlx, map->win,
		map->player->img, (j - 1) * 64, i * 64);
	map->player->count += 1;
	return ;
}
