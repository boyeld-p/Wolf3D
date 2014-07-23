/*
** my_igraph.h for my_igraph.h in
**
** Made by Brahic
** Login   <Spam@epitech.net>
**
** Started on  Wed Oct  9 11:04:46 2013 Brahic
** Last update Sun Jan 12 21:27:54 2014 brahic
*/

#ifndef MY_IGRAPH_H_
#define MY_IGRAPH_H_

/* TOUCHE AND DEFINE */
#define TITLE "_\\|WOLF3D|/_"
#define OPTIONS "./options/options.txt"
#define HAUT 65362
#define BAS 65364
#define GAUCHE 65361
#define DROITE 65363
#define ENTER 65293
#define ECHAP 65307
#define PAV8 65431
#define PAV2 65433
#define PAV7 65429
#define PAV9 65434
#define PAV1 65436
#define PAV3 65435
#define PLUS 65451
#define MOINS 65453
#define SPACE 32


/*DEFINE STRUCT T_MAP*/
#define MAX_X map->max_x
#define MAX_Y map->max_y
#define POS_X map->pos_map_x
#define POS_Y map->pos_map_y
#define MAP map->tab_map

/*DEFINE STRUCT T_OPTION*/
#define WIN_X opt->opt_x
#define WIN_Y opt->opt_y

/*DEFINE STRUCT T_RAY*/
#define RAY_X ray->ray_x
#define RAY_Y ray->ray_y
#define RAY_X_PRI ray->ray_x_pri
#define RAY_Y_PRI ray->ray_y_pri
#define DX ray->dx
#define DY ray->dy
#define ANGLE ray->angle
#define DIST ray->distance
#define	COEF ray->coef
#define	COEFX ray->coefx
#define	COEFY ray->coefy
#define FIND_X ray->find_x
#define FIND_Y ray->find_y
#define NB_PIX_WALL ray->nb_pix_wall

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "mlx.h"

/*Structure pour les images*/
typedef struct	s_img
{
  void		*img_ptr;
  char		*data;
  int		bpp;
  int		sizeline;
  int		endian;
}		t_img;

/*Structure pour les options*/
typedef struct	s_option
{
  int		opt_x;
  int		opt_y;
}		t_option;

/*Structure pour la map*/
typedef struct	s_map
{
  int		tab_map[300][300]; // faire un tableau d'int avec un malloc en fonction de la taille
  int		max_x;
  int		max_y;
  float		pos_map_x;
  float		pos_map_y;
  float		pos_map_x_init;
  float		pos_map_y_init;
}		t_map;

/*Structure pour le raytracer*/
typedef struct	s_ray
{
  float		ray_x;
  float		ray_y;
  float		ray_x_pri;
  float		ray_y_pri;
  float		distance;
  float		angle;
  float		coef;
  float		coefx;
  float		coefy;
  int		last_find_x;
  int		last_find_y;
  float		find_x;
  float		find_y;
  int		nb_pix_wall;
}		t_ray;

typedef struct	s_param
{
  void		*mlx_ptr;
  void		*win_ptr;
  void		*img_load_ptr;
  int		color;
  t_img		*pt_img;
  t_option	*pt_opt;
  t_ray		*pt_ray;
  t_map		*pt_map;
}		t_param;

int	gere_key(int keycode, t_param *param);
void	gere_key2(int keycode, t_param *param, float x, float y);
void	gere_key3(int keycode, t_param *param);

/*Initialiastion des valeurs du wolf3D*/
void    init_var(t_param *param, t_map *map, t_ray *ray);
void    init_win(t_param *param, t_img *img, t_option *opt, t_map *map);
void    get_option(const char *name_opt, t_option *opt);
void    get_map(char *file_map, t_map *map);
void	get_map2(int fd, t_map *map, int x, int y);

void	my_put_pix_img(t_param *param, int x, int y, int color);
void	my_error(const char *str);

/*Fonctionnement du Raycaster*/
void	my_raycast(t_option *opt, t_map *map, t_ray *ray, t_param *param);
void   find_wall(t_map *map, t_ray *ray);
void	draw_wall(t_param *param, t_ray *ray, t_option *opt, int x);
void	draw_wall_error(t_param *param, t_option *opt, int x);

void    draw_y(int x, int drawStart, int drawEnd, int color, t_param *param);

void	del_bloc(t_map *map, t_option *opt, t_ray *ray);
void	find_wall2(t_map *map, t_ray *ray);
void	add_bloc(t_map *map, t_option *opt, t_ray *ray);

#endif /* !MYIGRAPH_H_ */
