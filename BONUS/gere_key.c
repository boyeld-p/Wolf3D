/*
** gere_key.c for gere_key.c in /home/brahic_a/rendu/MUL_2013_wolf3d/BONUS
** 
** Made by brahic
** Login   <brahic_a@epitech.net>
** 
** Started on  Sun Jan 12 18:57:52 2014 brahic
** Last update Sun Jan 12 23:15:11 2014 brahic
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "mlx.h"
#include <math.h>
#include "my_igraph.h"
#include "my.h"
#include "X.h"

int	gere_key(int keycode, t_param *param)
{
  if (keycode == ECHAP)
    my_error("ECHAP\n");
  if (keycode == GAUCHE)
    {
      param->pt_ray->angle += 0.05;
      my_raycast(param->pt_opt, param->pt_map, param->pt_ray, param);
      mlx_put_image_to_window(param->mlx_ptr, param->win_ptr,
			      param->pt_img->img_ptr, 0, 0);
    }
  if (keycode == DROITE)
    {
      param->pt_ray->angle -= 0.05;
      my_raycast(param->pt_opt, param->pt_map, param->pt_ray, param);
      mlx_put_image_to_window(param->mlx_ptr, param->win_ptr,
			      param->pt_img->img_ptr, 0, 0);
    }
  gere_key2(keycode, param, 0, 0);
  gere_key3(keycode, param);
  printf("%d %d\n", param->pt_opt->opt_x, param->pt_opt->opt_y);
  mlx_string_put(param->mlx_ptr, param->win_ptr, param->pt_opt->opt_x / 2 - 10, param->pt_opt->opt_y, 0x000000, "|+|"); 
  return (0);
}

void	gere_key2(int keycode, t_param *param, float x, float y)
{
  if (keycode == HAUT)
    {
      x = param->pt_map->pos_map_x + cos(param->pt_ray->angle) * 0.1;
      y = param->pt_map->pos_map_y + sin(param->pt_ray->angle) * 0.1;
      if (param->pt_map->tab_map[(int)x][(int)y] <= 0)
	{
	  param->pt_map->pos_map_x += cos(param->pt_ray->angle) * 0.1;
	  param->pt_map->pos_map_y += sin(param->pt_ray->angle) * 0.1;
	  my_raycast(param->pt_opt, param->pt_map, param->pt_ray, param);
	  mlx_put_image_to_window(param->mlx_ptr, param->win_ptr,
				  param->pt_img->img_ptr, 0, 0);
	}
    }
  if (keycode == BAS)
    {
      x = param->pt_map->pos_map_x + cos(param->pt_ray->angle) * -0.1;
      y = param->pt_map->pos_map_y + sin(param->pt_ray->angle) * -0.1;
      if (param->pt_map->tab_map[(int)x][(int)y] <= 0)
	{
	  param->pt_map->pos_map_x += cos(param->pt_ray->angle) * -0.1;
	  param->pt_map->pos_map_y += sin(param->pt_ray->angle) * -0.1;
	  my_raycast(param->pt_opt, param->pt_map, param->pt_ray, param);
	  mlx_put_image_to_window(param->mlx_ptr, param->win_ptr,
				  param->pt_img->img_ptr, 0, 0);
	}
    }
}

void	gere_key3(int keycode, t_param *param)
{
  if (keycode == ENTER)
    {
      param->pt_ray->angle = 0;
      param->pt_map->pos_map_x = param->pt_map->pos_map_x_init;
      param->pt_map->pos_map_y = param->pt_map->pos_map_y_init;
      my_raycast(param->pt_opt, param->pt_map, param->pt_ray, param);
      mlx_put_image_to_window(param->mlx_ptr, param->win_ptr,
			      param->pt_img->img_ptr, 0, 0);
    }
  if (keycode == SPACE)
    {
      del_bloc(param->pt_map, param->pt_opt, param->pt_ray);
      my_raycast(param->pt_opt, param->pt_map, param->pt_ray, param);
      mlx_put_image_to_window(param->mlx_ptr, param->win_ptr,
			      param->pt_img->img_ptr, 0, 0);
    }
  if (keycode == PLUS)
    {
      add_bloc(param->pt_map, param->pt_opt, param->pt_ray);
      my_raycast(param->pt_opt, param->pt_map, param->pt_ray, param);
      mlx_put_image_to_window(param->mlx_ptr, param->win_ptr,
			      param->pt_img->img_ptr, 0, 0);
    }
}

void	del_bloc(t_map *map, t_option *opt, t_ray *ray)
{
  int	x;

  x = WIN_X / 2;
  RAY_X = 0.5;
  RAY_Y = ((0.5 * ((WIN_X * 0.5) - x)) / WIN_X);
  RAY_X_PRI = RAY_X * cos(ANGLE) - RAY_Y * sin(ANGLE) + POS_X;
  RAY_Y_PRI = RAY_X * sin(ANGLE) + RAY_Y * cos(ANGLE) + POS_Y;
  find_wall2(map, ray);
}

void	find_wall2(t_map *map, t_ray *ray)
{
  COEF = 0;
  FIND_X = RAY_X_PRI;
  FIND_Y = RAY_Y_PRI;
  while ((MAP[(int) FIND_X][(int) FIND_Y] <= 0) && COEF < 50)
    {
      FIND_X = (RAY_X_PRI - POS_X) * COEF + POS_X;
      FIND_Y = (RAY_Y_PRI - POS_Y) * COEF + POS_Y;
      COEF += 0.01;
    }
  MAP[(int) FIND_X][(int) FIND_Y] =  0;
  if (COEF < 50)
    DIST = sqrt(pow((FIND_X - POS_X), 2) + pow((FIND_Y - POS_Y), 2));
}

void	add_bloc(t_map *map, t_option *opt, t_ray *ray)
{
  float	x;
  float	y;

  (void) opt;
  x = map->pos_map_x + cos(ray->angle) * 2;
  y = map->pos_map_y + sin(ray->angle) * 2;
  MAP[(int) x][(int) y] =  1;
}
