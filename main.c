/*
** maintest1.c for maintest1 in
**
** Made by Brahic
** Login   <Spam@epitech.net>
**
** Started on  Thu Oct 24 09:33:35 2013 Brahic
** Last update Sun Jan 12 18:23:47 2014 brahic
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "mlx.h"
#include <math.h>
#include "my_igraph.h"
#include "my.h"
#include "X.h"

char		*strlcpy(char *dest, const char *src, size_t n)
{
  return (strncpy(dest, src, n));
}

int		gere_key(int keycode, t_param *param)
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

int	gere_expose(t_param *param)
{
  mlx_put_image_to_window(param->mlx_ptr, param->win_ptr,
			  param->pt_img->img_ptr, 0, 0);
  return (0);
}

int	main(int ac, char **av)
{
  t_param	param;
  t_img		img;
  t_option	opt;
  t_map		map;
  t_ray		ray;

  if (ac == 2)
    {
      get_option(OPTIONS, &opt);
      get_map(av[1], &map);
      init_var(&param, &map, &ray);
      init_win(&param, &img, &opt, &map);
      param.pt_ray = &ray;
      mlx_expose_hook(param.win_ptr, &gere_expose, &param);
      mlx_hook(param.win_ptr, 2, KeyPressMask, &gere_key, &param);
      mlx_loop_hook(param.mlx_ptr, &gere_key, &param);
      mlx_loop(param.mlx_ptr);
    }
  else
    my_printf("Usage : ./wolf \"map_file\"\n");
  return (0);
}
