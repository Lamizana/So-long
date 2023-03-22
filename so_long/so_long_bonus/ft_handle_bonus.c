/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:14:27 by alamizan          #+#    #+#             */
/*   Updated: 2023/01/23 08:27:15 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

int	handle_key(int key, t_map *map)
{
	static int	i = 0;

	ft_events_key(key, map);
	if (map->item->count == i)
	{
		if (i == 0)
			mlx_put_image_to_window(map->mlx, map->win,
				map->wall->img, 0, 64);
		else
			ft_event_item(map);
		i++;
	}
	ft_display_move(map);
	display_counter(map);
	return (0);
}

void	ft_events_key(int key, t_map *map)
{
	if (key == XK_Escape)
		ft_close(map);
	move_up(key, map);
	move_down(key, map);
	move_right(key, map);
	move_left(key, map);
}

void	ft_event_item(t_map *map)
{
	static int	pos = 1;
	int			count;

	count = 0;
	if (map->item->count == map->ground->count)
	{
		pos = 1;
		while (count < map->ground->count)
		{
			mlx_put_image_to_window(map->mlx, map->win,
				map->item_03->img, 0, pos * 64);
			pos += 1;
			count += 1;
		}
	}
	else
	{
		mlx_put_image_to_window(map->mlx, map->win,
			map->item_02->img, 0, pos * 64);
		map->item_02->count += 1;
		pos += 1;
	}
}

void	ft_game_over(t_map *map)
{
	ft_putstr_fd("\n\t\33[91m#############\33[0m\n", 1);
	ft_putstr_fd("\t\33[91m- GAME OVER -\33[0m\n", 1);
	ft_putstr_fd("\t\33[91m#############\33[0m\n\n", 1);
	ft_putstr_fd("You lose !\n", 1);
	ft_close(map);
}

void	ft_win(t_map *map)
{
	ft_putstr_fd("\n\t\33[94m#############\33[0m\n", 1);
	ft_putstr_fd("\t\33[94m - VICTORY -\33[0m\n", 1);
	ft_putstr_fd("\t\33[94m#############\33[0m\n\n", 1);
	ft_putstr_fd("You win !\n", 1);
	ft_close(map);
}
