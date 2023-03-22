/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:38:35 by alamizan          #+#    #+#             */
/*   Updated: 2023/01/20 14:33:39 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	ft_free(t_map *map)
{
	free(map->player);
	free(map->player_l);
	free(map->enemy);
	free(map->wall);
	free(map->door);
	free(map->ground);
	free(map->item);
	free(map->item_02);
	free(map->item_03);
	free(map);
}

void	ft_free_tmp(char **tmp, t_map *map)
{
	int	i;

	i = 0;
	while (i < map->line)
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

void	ft_destroy_image(t_map *map)
{
	mlx_destroy_image(map->mlx, map->player->img);
	mlx_destroy_image(map->mlx, map->player_l->img);
	mlx_destroy_image(map->mlx, map->enemy->img);
	mlx_destroy_image(map->mlx, map->ground->img);
	mlx_destroy_image(map->mlx, map->door->img);
	mlx_destroy_image(map->mlx, map->wall->img);
	mlx_destroy_image(map->mlx, map->item->img);
	mlx_destroy_image(map->mlx, map->item_02->img);
	mlx_destroy_image(map->mlx, map->item_03->img);
	mlx_loop_end(map->mlx);
	mlx_clear_window(map->mlx, map->win);
	mlx_destroy_window(map->mlx, map->win);
	mlx_destroy_display(map->mlx);
}

void	ft_error(t_map *map, int flag)
{
	int	i;

	i = 0;
	ft_putstr_fd("Error\n", 2);
	if (flag == 0)
		ft_putstr_fd("Invalid number of arguments.\n", 2);
	else if (flag == 1)
		ft_putstr_fd("Invalid format argument.\n", 2);
	else if (flag == 2)
		ft_putstr_fd("Invalid argument.\n", 2);
	else if (flag == 3)
	{
		ft_putstr_fd("Invalid map.\n", 2);
		while (i < map->line)
		{
			free(map->tab[i]);
			i++;
		}
		free(map->tab);
	}
	else if (flag == 4)
		ft_putstr_fd("No path available: Exit or Item blocked.\n", 2);
	ft_free(map);
	exit(0);
}

int	ft_close(t_map *map)
{
	int	i;

	i = 0;
	ft_destroy_image(map);
	while (i < map->line)
	{
		free(map->tab[i]);
		i++;
	}
	free(map->mlx);
	free(map->tab);
	ft_free(map);
	exit (0);
}
