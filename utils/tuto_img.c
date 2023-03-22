/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuto_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:03:36 by alamizan          #+#    #+#             */
/*   Updated: 2023/01/11 17:00:04 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>

// Pour ouverture fichiers
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// permet dobtenir les valeurs de tous les symboles dusponibles:
#include <X11/keysym.h>
#include <X11/X.h>

# include <stdio.h>
// clang tuto_img.c -I/usr/include -Imlx_linux  -Lmlx_linux mlx_linux/libmlx.a -lXext -lX11 -lm -lz -o to

# define WIN_HEIGHT 768
# define WIN_WIDTH 512
int main(void)
{
	void	*mlx;
	void	*win;
	void	*img_1;
	void	*img_2;
	void	*img_3;
	void	*perso_1;
	char	*relative_path = "./images/img_1.xpm";
	int		img_width;
	int		img_height;
	int		x;
	int		y;

	mlx = mlx_init();

	img_1 = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	img_2 = mlx_xpm_file_to_image(mlx, "./images/img_2.xpm", &img_width, &img_height);
	img_3 = mlx_xpm_file_to_image(mlx, "./images/img_3.xpm", &img_width, &img_height);
	
	// Initialisation perso:
	perso_1 = mlx_xpm_file_to_image(mlx, "./images/players_1.xpm", &img_width, &img_height);

	win = mlx_new_window(mlx, WIN_HEIGHT, WIN_WIDTH, "tuto image");
	x = 0;
	
	mlx_put_image_to_window(mlx, win, perso_1, WIN_HEIGHT/2, WIN_WIDTH/2);
	// Boucle pour creer des mur autour;
	while (x <= WIN_HEIGHT)
	{
		y = 0;
		mlx_put_image_to_window(mlx, win, img_1, x, y);
		while (y <= WIN_WIDTH)
		{
			if (x == 0)
				mlx_put_image_to_window(mlx, win, img_2, 0, y + 64);
			if (x > WIN_HEIGHT - 63)
				mlx_put_image_to_window(mlx, win, img_2, WIN_HEIGHT - 64 , y + 64);
			if (y > WIN_WIDTH -63)
				mlx_put_image_to_window(mlx, win, img_1, x + 64 , WIN_WIDTH - 64);
			y += 64;
		}
		x += 64;
	}
	mlx_put_image_to_window(mlx, win, img_3, 128, 0);
	mlx_loop(mlx);
}
