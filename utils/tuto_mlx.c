/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuto.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:49:56 by alamizan          #+#    #+#             */
/*   Updated: 2023/01/11 11:23:38 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
#include <stdio.h>

/* #######################################################################
  		 - PROJET SO_LONG -

- Utlisation de la MiniLibX.
	- mlx_init() -> permet d activer la minilibx.
		- renvoie un void *.
	- site utile -> 42 DOCS minilibx.

- Plusieurs man accessibles:
	- mlx_new_windows	: gestion fenetre.
	- mlx_pixel_put		: dessine dans la fenetre.
	- mlx_new_image		: manipule les images.
	- mlx_loop			: gestion clavier et souris.

- Compilation particuliere.
	- MiniLibx pour linux recquiert les dependances:
		-> xorg.
		-> x11.
		-> zlib.

- Creer une fenetre:
	- mlx_new_window(mlx_ptr, largeur, hauteur, "titre")

- Penser a fermer les fenetres et a free:
	- mlx_destroy_windows()	-> Libere toute les ressources alloue pour la fenetre:
	- mlx_destroy_display() -> Permet de fermer l affichage;
	- free(mlx_ptr).

- Creer une boucle pour garder la fenetre ouverte:
	- mlx_loop(mlx_ptr).

- Gestion erreur dans mlx_init() ou mlx_window():
	- si erreur alors le pointeur renvoie NULL.

- Dessiner des pixels sur la fenetre:
	- fonction -> mlx_pixel_put(mlx_ptr, win_ptr, int x, int y, int color);
	- x: numero de colonne.
	- y: numero de ligne>
	- PROBLEME: ne stocke pas les pixels sur une image 
				mais les affiche directement.

- Creer une image et dessiner dessus avant de l envoyer dans la fenetre:
	- void *mlx_new_image(void *mlx_ptr, int width, int heignt);
	-creer une structure qui contient toute les donnees necessaires.

- Enregistrer des evenements avec les hooks de minilibx:
	- int mlx_mouse_hook(void *win_ptr, int (*funct_ptr(), void *param));
	- int mlx_key_hook(void *win_ptr, int (*funct_ptr(), void *param));
	- int mlx_expose_hook(void *win_ptr, int (*funct_ptr(), void *param));
--> evenement liee a la souris, au clavier et les evenements d expositions.
	
- Utilisation des evenements:
	- handle_input -> fct executee a chaque relachement d une touche.
		#include<X11/keysym.h
########################################################################## */

// Definit la largeur(width) et la hauteur(height) de la fenetre:
// Resolution courante --> 1920 x 1080.
#define WINDOW_WIDTH 700
#define WINDOW_HEIGHT 500

// --------------------------------------------------------
// Definit couleur pixel en hexadecimal:
#define RED_PIXEL			0xFF0000
#define BLUE_PIXEL			0x0000FF
#define GREEN_PIXEL			0x008000
#define ALICE_BLUE_PIXEL	0xF0F8FF
#define FIRE_PIXEL			0xFF69B4
#define CORAIL_PIXEL		0xFF7F50
// --------------------------------------------------------

// --------------------------------------------------------
// Structure pour creer une image:
typedef struct	s_img
{
	void	*mlx_img;	// pointe sur mlx_new_image.
	char	*addr;		// renvoie l addresse de l img sous forme d 1 tableau de pixels.
	int		bpp;		// nombre de bits par pixel.
	int		line_len;
	int		endian;
}	t_img;

// Creation structure pour les pointeurs fenetre et init:
typedef struct s_data
{
	void	*mlx_ptr; // Affecte emplacement memoire pour mlx.
	void	*win_ptr; // Affecte un emplacement mem>
	t_img	img;
}	t_data;

// Structure pour creer un rectangle:
typedef struct s_rect
{
	int	x;			// point de depart horizontal.
	int	y;			// point de depart vertical.
	int	width;		// point d arrivee horizontal.
	int	height;		// point d arrivee vertical.
	int	color;		// couleurs en hexadecimale.
}	t_rect;
// --------------------------------------------------------
// Fonctions d evenements:
int handle_no_event(void *data)
{
	return (0);
}

// Ferme la fenetre si touche escape est presse:
int handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	printf("Touche pressee: %d --> %c\n", keysym, keysym);
	return (0);
}

// Affiche la touche relachee:
int	handle_keyrelease(int keysym, void *data)
{
	printf("Touche relachee: %d --> %c\n", keysym, keysym);
	return (0);
}

// Creation d une image qui ecrira des pixels au coordonnees donner:
void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	// index = line_len * y + x * (bpp / 8).
	pixel = img->addr + ((y * img->line_len) + (x * (img->bpp / 8)));
	*(int *)pixel = color;
}
// --------------------------------------------------------
// Creation d un rectangle:
int render_rect(t_img *img, t_rect rect)
{
	int	i;	// -> y
	int	j;	// -> x

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
		{
			img_pix_put(img, j, i, rect.color);
			j++;
		}
		i++;
	}
	return (0);
}
// Creer un ensemble de formes
void	ft_display_img1(t_img *img)
{
	// rectangle vide BLANC:
	render_rect(img, (t_rect){100, 40, 3, 400, ALICE_BLUE_PIXEL});
	render_rect(img, (t_rect){100, 40, 200, 3, ALICE_BLUE_PIXEL});
	render_rect(img, (t_rect){300, 40, 3, 100, ALICE_BLUE_PIXEL});
	render_rect(img, (t_rect){300, 140, 100, 3, ALICE_BLUE_PIXEL});
	render_rect(img, (t_rect){400, 40, 3, 103, ALICE_BLUE_PIXEL});
	render_rect(img, (t_rect){400, 40, 203, 3, ALICE_BLUE_PIXEL});
	render_rect(img, (t_rect){600, 40, 3, 400, ALICE_BLUE_PIXEL});
	render_rect(img, (t_rect){100, 440, 503, 3, ALICE_BLUE_PIXEL});
}

void	ft_display_img2(t_img *img)
{
	// Plusieurs carrees:
	render_rect(img, (t_rect){150, 70, 100, 100, RED_PIXEL});
	render_rect(img, (t_rect){250, 170, 100, 100, BLUE_PIXEL});
	render_rect(img, (t_rect){350, 170, 100, 100, BLUE_PIXEL});
	render_rect(img, (t_rect){300, 270, 100, 10, GREEN_PIXEL});
	render_rect(img, (t_rect){450, 70, 100, 100, RED_PIXEL});
	render_rect(img, (t_rect){450, 270, 100, 100, RED_PIXEL});
	render_rect(img, (t_rect){150, 270, 100, 100, RED_PIXEL});
}

// Changer la couleur du fond:
int	render_background(t_img *img, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x < WINDOW_HEIGHT)
	{
		y = 0;
		while (y < WINDOW_WIDTH)
		{
			img_pix_put(img, y, x, color);
			y++;
		}
		x++;
	}
	return (0);
}

// --------------------------------------------------------
// Affiche le rendu de mes fenetres:
int	render(t_data *data)
{
	// Si la fenetre n est pas detruite:
	if (data->win_ptr == NULL)
		return (1);
	//img_pix_put(img, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, ALICE_BLUE_PIXEL);
	//render_rect(&data->img, (t_rect){WINDOW_WIDTH - 250, WINDOW_HEIGHT -150, 250, 150, GREEN_PIXEL});

	// creer l image:
	//render_background(&data->img, CORAIL_PIXEL);
	ft_display_img1(&data->img);
	ft_display_img2(&data->img);
	
	// Pousse l image mise a jour sur la fenetre:
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

// --------------------------------------------------------
int	main(void)
{
	//void	*mlx_ptr;
	//void	*win_ptr;
	t_data	data;

	// Initialise et cree une fenetre + gestion d erreurs:
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "mlx 42");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (1);
	}

	// Creation de l image:
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);

	// Creation des evenements -> Utilisations des fonctions:
	//mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data);

	// Ouvre la fenetre et permet la gestion des evenements:
	mlx_loop(data.mlx_ptr);
	
	// Ferme les fenetres et free:
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);	
	return (0);
}
