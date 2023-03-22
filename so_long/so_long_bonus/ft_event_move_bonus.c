/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_move_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:34:22 by alamizan          #+#    #+#             */
/*   Updated: 2023/01/20 09:08:33 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	event_up(t_map *map, int i, int j)
{
	if (map->tab[i - 1][j] == 'M')
		ft_game_over(map);
	if (map->tab[i - 1][j] == 'C')
		map->item->count += 1;
	else if (map->tab[i - 1][j] == 'E')
	{
		if (map->ground->count == map->item->count)
			ft_win(map);
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
	map->tab[i - 1][j] = 'P';
	map->tab[i][j] = '0';
	return ;
}

void	event_down(t_map *map, int i, int j)
{
	if (map->tab[i + 1][j] == 'M')
		ft_game_over(map);
	if (map->tab[i + 1][j] == 'C')
		map->item->count += 1;
	else if (map->tab[i + 1][j] == 'E')
	{
		if (map->ground->count == map->item->count)
			ft_win(map);
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
	return ;
}

void	event_right(t_map *map, int i, int j)
{
	if (map->tab[i][j + 1] == 'M')
		ft_game_over(map);
	if (map->tab[i][j + 1] == 'C')
		map->item->count += 1;
	else if (map->tab[i][j + 1] == 'E')
	{
		if (map->ground->count == map->item->count)
			ft_win(map);
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
	if (map->tab[i][j - 1] == 'M')
		ft_game_over(map);
	if (map->tab[i][j - 1] == 'C')
		map->item->count += 1;
	else if (map->tab[i][j - 1] == 'E')
	{	
		if (map->ground->count == map->item->count)
			ft_win(map);
		else
			return ;
	}
	map->tab[i][j - 1] = 'P';
	map->tab[i][j] = '0';
	mlx_put_image_to_window(map->mlx, map->win,
		map->ground->img, j * 64, i * 64);
	mlx_put_image_to_window(map->mlx, map->win,
		map->player_l->img, (j - 1) * 64, i * 64);
	map->player->count += 1;
	return ;
}
