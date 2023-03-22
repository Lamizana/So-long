/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:16:54 by alamizan          #+#    #+#             */
/*   Updated: 2023/01/23 08:22:31 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_display_img(t_map *map, int i, int j)
{
	if (map->tab[i][j] == '1')
		mlx_put_image_to_window(map->mlx, map->win,
			map->wall->img, j * PIXEL, i * PIXEL);
	else if (map->tab[i][j] == '0')
		mlx_put_image_to_window(map->mlx, map->win,
			map->ground->img, j * PIXEL, i * PIXEL);
	else if (map->tab[i][j] == 'E')
		mlx_put_image_to_window(map->mlx, map->win,
			map->door->img, j * PIXEL, i * PIXEL);
	else if (map->tab[i][j] == 'P')
		mlx_put_image_to_window(map->mlx, map->win,
			map->player->img, j * PIXEL, i * PIXEL);
	else if (map->tab[i][j] == 'C')
		mlx_put_image_to_window(map->mlx, map->win,
			map->item->img, j * PIXEL, i * PIXEL);
}

void	display_image(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->line)
	{
		j = 0;
		while (j < map->len)
		{
			ft_display_img(map, i, j);
			j++;
		}
		i++;
	}
}

void	display_counter(t_map *map)
{
	ft_putstr_fd("- Total Item: ", 1);
	ft_putnbr_fd(map->ground->count, 1);
	write(1, "\n", 1);
	ft_putstr_fd("- Move counter: ", 1);
	ft_putnbr_fd(map->player->count, 1);
	write(1, "\n", 1);
	ft_putstr_fd("- Item counter: ", 1);
	ft_putnbr_fd(map->item->count, 1);
	write(1, "\n", 1);
	ft_putstr_fd("----------------------------\n", 1);
}
