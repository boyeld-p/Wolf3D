/*
** maintest1.c for maintest1 in
**
** Made by Brahic
** Login   <Spam@epitech.net>
**
** Started on  Thu Oct 24 09:33:35 2013 Brahic
** Last update Sun Jan 12 23:15:09 2014 brahic
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

int	gere_mouse(t_param *param, int x, int y)
{
  (void) param;
  (void) x;
  (void) y;
  printf("x : %d y : %d\n", x, y);
  return (0);
}

int	gere_expose(t_param *param)
{
  mlx_put_image_to_window(param->mlx_ptr, param->win_ptr,
			  param->pt_img->img_ptr, 0, 0);
  mlx_string_put(param->mlx_ptr, param->win_ptr, param->pt_opt->opt_x / 2 - 10, param->pt_opt->opt_y, 0x000000, "|+|");
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
      mlx_hook(param.win_ptr, 4, ButtonPress, &gere_mouse, &param);
      mlx_loop(param.mlx_ptr);
    }
  else
    my_printf("Usage : ./wolf \"map_file\"\n");
  return (0);
}
