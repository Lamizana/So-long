# - PROJET SO_LONG -		     

Petit jeux 2D avec la minilibx 42

## - Utlisation de la MiniLibX.
	- mlx_init() -> permet d activer la minilibx.
		- renvoie un void *.
	- site utile -> 42 DOCS minilibx.

## - Plusieurs man accessibles:
	- mlx_new_windows	: gestion fenetre.
	- mlx_pixel_put		: dessine dans la fenetre.
	- mlx_new_image		: manipule les images.
	- mlx_loop		: gestion clavier et souris.

## - Compilation particuliere.
	- MiniLibx pour linux recquiert les dependances:
		-> xorg.
		-> x11.
		-> zlib.

## - Creer une fenetre:
	- mlx_new_window(mlx_ptr, largeur, hauteur, "titre")

1. Penser a fermer les fenetres et a free:
	- mlx_destroy_windows()	-> Libere toute les ressources alloue pour la fenetre:
	- mlx_destroy_display() -> Permet de fermer l affichage;
	- free(mlx_ptr).

2. Creer une boucle pour garder la fenetre ouverte:
	- mlx_loop(mlx_ptr).

3. Gestion erreur dans mlx_init() ou mlx_window():
	- si erreur alors le pointeur renvoie NULL.


4. Utlisation de la MiniLibX.
	- mlx_init() -> permet d activer la minilibx.
		- renvoie un void *.
	- site utile -> 42 DOCS minilibx.

## - Plusieurs man accessibles:
	- mlx_new_windows	: gestion fenetre.
	- mlx_pixel_put		: dessine dans la fenetre.
	- mlx_new_image		: manipule les images.
	- mlx_loop		: gestion clavier et souris.
