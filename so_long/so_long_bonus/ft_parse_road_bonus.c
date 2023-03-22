/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_road_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:11:13 by alamizan          #+#    #+#             */
/*   Updated: 2023/01/19 13:59:15 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	ft_free_map_and_road(char **tmp, t_map *map, int x, int y)
{
	int	i;

	if (tmp[y][x] == 'C' || tmp[y][x] == 'E')
	{
		ft_free_tmp(tmp, map);
		i = 0;
		while (i < map->line)
		{
			free(map->tab[i]);
			i++;
		}
		free(map->tab);
		ft_error(map, 4);
	}
}

char	**duplicate_map(t_map *map)
{
	char	**tmp;
	int		i;
	int		j;

	tmp = malloc(sizeof(char *) * map->line);
	if (!tmp)
		return (0);
	i = 0;
	while (i < map->line)
	{
		tmp[i] = malloc(sizeof(char) * (map->len));
		i++;
	}
	i = 0;
	while (i < map->line)
	{
		j = 0;
		while (j < map->len)
		{
			tmp[i][j] = map->tab[i][j];
			j++;
		}
		i++;
	}
	return (tmp);
}

void	check_start(char **tmp, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	ft_parse_road(tmp, map);
	while (y < map->line)
	{
		x = 0;
		while (x < map->len)
		{
			ft_free_map_and_road(tmp, map, x, y);
			x++;
		}
		y++;
	}
	ft_free_tmp(tmp, map);
}

void	ft_parse_road(char **tmp, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->line)
	{
		x = 0;
		while (x < map->len)
		{
			if (tmp[y][x] == 'P')
				parse_road(tmp, x, y);
			x++;
		}
		y++;
	}
}

void	parse_road(char **tmp, int x, int y)
{
	if (tmp[y][x] == 'E' || tmp[y][x] == 'X' || tmp[y][x] == 'M')
	{
		if (tmp[y][x] == 'E')
			tmp[y][x] = 'X';
		if (tmp[y][x] == 'M')
			tmp[y][x] = 'X';
		return ;
	}
	else if (tmp[y][x] != '1')
	{
		tmp[y][x] = 'X';
		parse_road(tmp, x + 1, y);
		parse_road(tmp, x - 1, y);
		parse_road(tmp, x, y + 1);
		parse_road(tmp, x, y - 1);
	}
}
