/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:30:44 by alamizan          #+#    #+#             */
/*   Updated: 2023/01/23 13:39:46 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	fd_error(t_map *map)
{
	if (map->fd == -1)
		ft_error(map, 3);
}

void	line_counter(t_map *map)
{
	char	*ret;

	ret = get_next_line(map->fd);
	if (ret == 0)
		ft_error(map, 3);
	map->len = ft_strlen(ret);
	while (ret != NULL)
	{
		free(ret);
		map->line++;
		ret = get_next_line(map->fd);
		if (ret == NULL)
			free(ret);
	}
}

void	open_file(int argc, char *argv[], t_map *map)
{
	int		i;
	char	**tmp;

	tmp = NULL;
	check_arg(argc, argv, map);
	i = 0;
	map->line = 0;
	map->len = 0;
	map->fd = open(argv[1], O_RDONLY);
	fd_error(map);
	line_counter(map);
	map->tab = malloc(sizeof(char *) * (map->line));
	close(map->fd);
	map->fd = open(argv[1], O_RDONLY);
	fd_error(map);
	while (i < map->line)
		map->tab[i++] = get_next_line(map->fd);
	get_next_line(map->fd);
	close(map->fd);
	parse_door_player(map);
	parse_wall(map);
	parse_item(map);
	tmp = duplicate_map(map);
	check_start(tmp, map);
}

void	ft_putstr_fd(char *str, int fd)
{
	if (!str)
		return ;
	while (*str != '\0')
	{
		write(fd, str, 1);
		str++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		if (n == -2147483648)
			write(fd, "-2147483648", 11);
		else
		{
			write(fd, "-", 1);
			ft_putnbr_fd(-n, fd);
		}
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else if (n < 10)
	{
		n = '0' + n;
		write(fd, &n, 1);
	}
}
