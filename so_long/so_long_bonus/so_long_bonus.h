/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:07:53 by alamizan          #+#    #+#             */
/*   Updated: 2023/01/23 08:26:35 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define PIXEL 64

# define RED_PIXEL			0xFF0000
# define BLUE_PIXEL			0x0000FF
# define GREEN_PIXEL		0x008000
# define ALICE_BLUE_PIXEL	0xF0F8FF
# define FIRE_PIXEL			0xFF69B4
# define CORAIL_PIXEL		0xFF7F50

# include "../gnl/get_next_line.h"
# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include <X11/keysym.h>
# include <X11/X.h>

/* STRUCTURE */
typedef struct s_image
{
	void	*img;
	int		img_x;
	int		img_y;
	int		count;
}			t_image;

typedef struct s_map
{
	void	*mlx;
	void	*win;
	char	**tab;
	int		line;
	int		len;
	int		fd;
	t_image	*player;
	t_image	*player_l;
	t_image	*enemy;
	t_image	*ground;
	t_image	*wall;
	t_image	*door;
	t_image	*item;
	t_image	*item_02;
	t_image	*item_03;
}			t_map;

/* PARSING MAP AND ROAD --> ft_parsing.c / ft_parse_road.c */
void	check_arg(int argc, char *argv[], t_map *map);
void	check_alphanum(t_map *map, int i, int j);
int		parse_door_player(t_map *map);
int		parse_wall(t_map *map);
void	parse_item(t_map *map);

char	**duplicate_map(t_map *map);
void	check_start(char **tmp, t_map *map);
void	ft_parse_road(char **tmp, t_map *map);
void	parse_road(char **tmp, int x, int y);
void	ft_free_map_and_road(char **tmp, t_map *map, int x, int y);

/* INIT MAP AND STRUCTURE --> ft_inits.c */
void	init_map(t_map *map);
void	init_struct(t_map *map);
void	init_images(t_map *map);
void	line_counter(t_map *map);
void	open_file(int argc, char *argv[], t_map *map);

/* ERROR  AND FREE --> ft_errors.c */
void	ft_error(t_map *map, int flag);
void	ft_destroy_image(t_map *map);
void	ft_free_tmp(char **tmp, t_map *map);
void	ft_free(t_map *map);
int		ft_close(t_map *map);

/* EVENTS --> ft_move.c / ft_event_move.c / ft_handle.c */
void	move_up(int key, t_map *map);
void	move_down(int key, t_map *map);
void	move_right(int key, t_map *map);
void	move_left(int key, t_map *map);

void	event_up(t_map *map, int i, int j);
void	event_down(t_map *map, int i, int j);
void	event_right(t_map *map, int i, int j);
void	event_left(t_map *map, int i, int j);

int		handle_key(int key, t_map *map);
void	ft_events_key(int key, t_map *map);
void	ft_event_item(t_map *map);
void	ft_game_over(t_map *map);
void	ft_win(t_map *map);

/* DISPLAY --> ft_display.c */
void	display_image(t_map *map);
void	ft_display_move(t_map *map);
void	display_counter(t_map *map);
void	ft_display_img(t_map *map, int i, int j);

/* UTILS --> so_long_utils.c */
char	*ft_itoa(int nb);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(int n, int fd);
#endif
