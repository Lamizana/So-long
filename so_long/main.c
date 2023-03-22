/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:30:43 by alamizan          #+#    #+#             */
/*   Updated: 2023/01/23 13:32:25 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	main(int argc, char*argv[])
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (0);
	init_struct(map);
	open_file(argc, argv, map);
	init_map(map);
	display_image(map);
	mlx_hook(map->win, KeyPress, KeyPressMask, &handle_key, map);
	mlx_hook(map->win, 17, 1L << 0, *ft_close, map);
	mlx_loop(map->mlx);
	ft_close(map);
	return (0);
}
