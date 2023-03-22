/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:34:48 by alamizan          #+#    #+#             */
/*   Updated: 2023/01/23 08:25:38 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	check_alphanum(t_map *map, int i, int j)
{
	if (map->tab[i][j] != '0' && map->tab[i][j] != '1'
			&& map->tab[i][j] != 'E' && map->tab[i][j] != 'C'
			&& map->tab[i][j] != 'P' && map->tab[i][j] != 'M')
		ft_error(map, 3);
}

void	check_arg(int argc, char *argv[], t_map *map)
{
	int	i;

	if (argc != 2)
	{
		ft_error(map, 0);
	}
	i = ft_strlen(argv[1]) - 1;
	if ((argv[1][i] != 'r' || argv[1][i - 1] != 'e' || argv[1][i - 2] != 'b'
			|| argv[1][i - 3] != '.') || ft_strlen(argv[1]) < 5)
		ft_error(map, 1);
}

int	parse_wall(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->len)
	{
		if (map->tab[0][i] != '1' || map->tab[map->line - 1][i] != '1')
			ft_error(map, 3);
		i++;
	}
	i = 1;
	while (i < map->line)
	{
		if (map->len != (int)ft_strlen(map->tab[i]))
			ft_error(map, 3);
		if (map->tab[i][0] != '1' || map->tab[i][map->len -1] != '1')
			ft_error(map, 3);
		i++;
	}
	return (0);
}

int	parse_door_player(t_map *map)
{
	int	i;
	int	j;
	int	count_exit;
	int	count_player;

	i = 0;
	count_exit = 0;
	count_player = 0;
	while (i < map->line)
	{
		j = 0;
		while (map->tab[i][j] && i < map->len)
		{
			if (map->tab[i][j] == 'E')
				count_exit += 1;
			else if (map->tab[i][j] == 'P')
				count_player += 1;
			j++;
		}
		i++;
	}
	if (count_exit != 1 || count_player != 1)
		ft_error(map, 3);
	return (0);
}

void	parse_item(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->line)
	{
		j = 0;
		while (j < map->len)
		{
			check_alphanum(map, i, j);
			if (map->tab[i][j] == 'C')
				map->ground->count += 1;
			j++;
		}
		i++;
	}
	if (map->ground->count == 0)
		ft_error(map, 3);
	return ;
}
