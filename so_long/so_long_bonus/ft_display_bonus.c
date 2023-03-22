/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:16:54 by alamizan          #+#    #+#             */
/*   Updated: 2023/01/23 14:14:19 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

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
	else if (map->tab[i][j] == 'M')
		mlx_put_image_to_window(map->mlx, map->win,
			map->enemy->img, j * PIXEL, i * PIXEL);
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
	mlx_string_put(map->mlx, map->win, 1, 45,
		ALICE_BLUE_PIXEL, "Item counter:");
	mlx_string_put(map->mlx, map->win, (map->len * PIXEL) - 140, 45,
		ALICE_BLUE_PIXEL, "Move counter: ");
}

void	ft_display_move(t_map *map)
{
	char	*move_count;

	move_count = ft_itoa(map->player->count);
	mlx_put_image_to_window(map->mlx, map->win,
		map->wall->img, (map->len - 1) * PIXEL, 0);
	mlx_string_put(map->mlx, map->win, (map->len * PIXEL) - 36, 45,
		ALICE_BLUE_PIXEL, move_count);
	free(move_count);
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
	ft_putstr_fd("--------------------------------\n", 1);
}
