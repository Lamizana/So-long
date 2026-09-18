<div align="center">

<p align="center">
  <a href="https://fr.wikipedia.org/wiki/C_(langage)"><img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="C Language"></a>
  <a href="https://github.com/42School/norminette"><img src="https://img.shields.io/badge/Norminette-v4-brightgreen?style=for-the-badge&logo=42&logoColor=white" alt="Norminette"></a>
  <a href="https://github.com/42Paris/minilibx-linux"><img src="https://img.shields.io/badge/MiniLibX-Linux-orange?style=for-the-badge&logo=linux&logoColor=white" alt="MiniLibX Linux"></a>
  <a href="https://fr.wikipedia.org/wiki/École_42"><img src="https://img.shields.io/badge/Licence-42-lightgrey?style=for-the-badge&logo=42&logoColor=white" alt="Licence 42"></a>
</p>

# So long

<p align="center">
  <strong>Projet 42</strong>
</p>

<p align="center">
  Petit jeu 2D réalisé avec la MiniLibX
</p>

</div>

---

## À propos

`So_long` est un projet de l'école 42 qui consiste à créer un petit jeu vidéo 2D
en langage **C** à l'aide de la bibliothèque graphique **MiniLibX**.

Le joueur évolue dans un labyrinthe, doit **collecter tous les objets** puis
atteindre la **sortie** pour terminer le niveau. Le projet valide également la
maîtrise de la gestion de la mémoire, du parsing de fichiers et des événements
clavier/souris.

---

## Fonctionnalités

### Partie obligatoire

- Lecture et validation de cartes au format `.ber`
- Vérification rigoureuse : bordures fermées, présence d'un seul joueur et d'une seule sortie, au moins un collectible
- Validation du chemin par **flood-fill** (tous les objets et la sortie doivent être atteignables)
- Déplacements au clavier (**ZQSD**)
- Collecte des objets et ouverture de la sortie
- Fenêtre `mlx_new_window` avec rendu des sprites en **XPM**
- Gestion complète de la mémoire (pas de fuites)

### Bonus

- Ennemi (slime) présent sur la carte (symbole `M`) — le toucher = game over
- Compteur de mouvements affiché à l'écran
- Écrans de **victoire** et de **game over**
- Sprites supplémentaires (joueur tête à gauche, variantes d'objets)
- Fermeture propre via la touche `Échap` ou la croix de la fenêtre

---

## Prérequis

Le projet est développé pour **Linux** (X11).

<div align="center">

| Dépendance   | Description                          |
|--------------|--------------------------------------|
| `gcc` / `clang` | Compilateur C                     |
| `xorg`       | Serveur graphique X11                |
| `x11-dev`    | En-têtes et bibliothèques X11        |
| `zlib1g-dev` | Compression (requis par le chargement XPM) |

</div>

### Installation des dépendances (Debian/Ubuntu)

```bash
sudo apt-get update
sudo apt-get install -y build-essential libx11-dev libxext-dev zlib1g-dev
```

> **Note** : la MiniLibX Linux est fournie dans le dépôt (dossier `mlx_linux/`)
> et est compilée automatiquement par le `Makefile`.

---

## Installation et utilisation

### Compilation

```bash
make            # compile la partie obligatoire → binaire « so_long »
make bonus      # compile la partie bonus      → binaire « solong_bonus »
```

### Nettoyage

```bash
make clean      # supprime les fichiers objets (.o)
make fclean     # supprime les objets et les binaires
make re         # recompile depuis zéro
```

### Lancer le jeu

```bash
./so_long carte_01.ber          # partie obligatoire
./solong_bonus carte_03_bonus.ber   # partie bonus
```

---

## Contrôles

<div align="center">

| Touche        | Action                                |
|---------------|---------------------------------------|
| `Z` (↑)       | Déplacer le joueur vers le haut       |
| `Q` (←)       | Déplacer le joueur vers la gauche     |
| `S` (↓)       | Déplacer le joueur vers le bas        |
| `D` (→)       | Déplacer le joueur vers la droite     |
| `Échap` / `Esc` | Fermer le jeu proprement (partie bonus) |

</div>

> Le compteur de mouvements est incrémenté à chaque déplacement du joueur.

---

## Format de la carte (`.ber`)

Les cartes sont des fichiers texte dont chaque caractère représente une tuile.
Le fichier doit être **entouré de murs** (`1`) et peut être suivi d'un saut de
ligne final.

<div align="center">
  
| Symbole | Signification            |
|---------|--------------------------|
| `0`     | Sol vide                 |
| `1`     | Mur                      |
| `C`     | Objet à collecter        |
| `E`     | Sortie                   |
| `P`     | Position de départ       |
| `M`     | Ennemi *(bonus)*         |

</div>

### Exemple

```text
1111111111111
1001000000001
1000011111C01
1P0011C0E0001
1111111111111
```

---

## Structure du projet

```
so_long/
├── Makefile                  # Système de compilation
├── so_long.h                 # En-tête principal (structures + prototypes)
├── main.c                    # Point d'entrée
├── ft_inits.c                # Initialisation des structures, images et fenêtre
├── ft_parsing.c              # Validation de la carte
├── ft_parse_road.c           # Validation du chemin (flood-fill)
├── ft_errors.c               # Gestion des erreurs et libération mémoire
├── ft_display.c              # Rendu des tuiles et de la fenêtre
├── ft_move.c                 # Déplacements (ZQSD)
├── ft_event_move.c           # Événements (collecte, sortie, déplacements)
├── so_long_utils.c           # Utilitaires (lecture fichier, GNL, affichage)
├── gnl/                      # Bibliothèque « Get Next Line » (lecture ligne)
├── mlx_linux/                # MiniLibX (Linux) fournie localement
├── images/                   # Sprites au format XPM (64×64)
└── so_long_bonus/            # Fichiers sources de la partie bonus
```

---

## Détails techniques

- **MiniLibX** : chargement des images via `mlx_xpm_file_to_image`, rendu par
  `mlx_put_image_to_window`.
- **Parsing** : vérification du nombre d'arguments, caractères autorisés,
  murs sur les bordures, unicité de `P` et `E`, présence d'au moins un `C`.
- **Vérification de chemin** : copie de la carte puis **flood-fill récursif**
  depuis la position du joueur pour garantir que tous les objets et la sortie
  sont accessibles.
- **Fin de partie** : la sortie ne peut être franchie qu'une fois tous les
  objets collectés.
- **Norme 42** : code écrit selon la Norminette (en-têtes 42, indentation tabs,
  lignes ≤ 80 caractères).

---

## Test

Plusieurs cartes de test sont fournies dans le dossier `so_long/` :

<div align="center">

| Fichier              | Description                          |
|----------------------|--------------------------------------|
| `carte_01.ber`       | Carte simple (partie obligatoire)    |
| `carte_02.ber`       | Carte test (partie obligatoire)      |
| `carte_03.ber`       | Carte test (partie obligatoire)      |
| `carte_03_bonus.ber` | Carte avec ennemis `M` *(bonus)*     |
| `carte_04_bonus.ber` | Carte bonus                         |

</div>

---


## Auteur

**Alex Lamizana** : Étudiant 42 Angoulême, spécialisation Data & IA

- [Site](https://lamizana.github.io/ZehdBox/)
- [GitHub](https://github.com/Lamizana)


<div align="center">

*Ce projet a été réalisé conformément à la norme et au sujet officiel de 42.*

</div>
