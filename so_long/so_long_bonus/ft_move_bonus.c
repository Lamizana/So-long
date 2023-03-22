/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:54:09 by alamizan          #+#    #+#             */
/*   Updated: 2023/01/23 14:18:06 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	move_up(int key, t_map *map)
{
	int	i;
	int	j;

	if (key != 65362)
		return ;
	i = 0;
	while (i < map->line)
	{
		j = 0;
		while (j < map->len)
		{
			if ((map->tab[i][j] == 'P') && (map->tab[i - 1][j] != '1'))
				event_up(map, i, j);
			j++;
		}
		i++;
	}
}

void	move_down(int key, t_map *map)
{
	int	i;
	int	j;

	if (key != 65364)
		return ;
	i = 0;
	while (i < map->line)
	{
		j = 0;
		while (j < map->len)
		{
			if ((map->tab[i][j] == 'P') && (map->tab[i + 1][j] != '1'))
			{
				event_down(map, i, j);
				return ;
			}
			j++;
		}
		i++;
	}
	return ;
}

void	move_right(int key, t_map *map)
{
	int	i;
	int	j;

	if (key != 65363)
		return ;
	i = 0;
	while (i < map->line)
	{
		j = 0;
		while (j < map->len)
		{
			if ((map->tab[i][j] == 'P') && (map->tab[i][j + 1] != '1'))
			{
				event_right(map, i, j);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	move_left(int key, t_map *map)
{
	int	i;
	int	j;

	if (key != 65361)
		return ;
	i = 0;
	while (i < map->line)
	{
		j = 0;
		while (j < map->len)
		{
			if ((map->tab[i][j] == 'P') && (map->tab[i][j - 1] != '1'))
				event_left(map, i, j);
			j++;
		}
		i++;
	}
}
