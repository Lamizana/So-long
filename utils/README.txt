# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    README.txt                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alamizan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 13:14:05 by alamizan          #+#    #+#              #
#    Updated: 2023/01/10 13:15:26 by alamizan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

####################################
#		- PROJET SO_LONG -		   #
####################################

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

