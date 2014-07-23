/*
** my_uti2.c for my_uti2.c in /home/brahic_a/rendu/MUL_2013_wolf3d
** 
** Made by brahic
** Login   <brahic_a@epitech.net>
** 
** Started on  Sun Jan 12 18:15:00 2014 brahic
** Last update Sun Jan 12 18:32:02 2014 brahic
*/

#include "mlx.h"
#include "my_igraph.h"
#include "my.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include <stdio.h>

void	init_var(t_param *param, t_map *map, t_ray *ray)
{
  (void) param;
  if (POS_X < 0 || POS_X > 300)
    POS_X = 1;
  if (POS_Y < 0 || POS_Y > 300)
    POS_Y = 1;
  ANGLE = 0;
}

void	init_win(t_param *param, t_img *img, t_option *opt, t_map *map)
{
  if ((param->mlx_ptr = mlx_init()) == NULL)
    my_error("ERROR MLX_INIT\n");
  param->pt_img = img;
  param->pt_opt = opt;
  param->pt_map = map;
  param->win_ptr = mlx_new_window
    (param->mlx_ptr, param->pt_opt->opt_x, param->pt_opt->opt_y, TITLE);
  if (param->win_ptr == NULL)
    my_error("ERROR MLX_NEW_WINDOWS\n");
  img->img_ptr = mlx_new_image
    (param->mlx_ptr, param->pt_opt->opt_x, param->pt_opt->opt_y);
  if (img->img_ptr == NULL)
    my_error("ERROR MLX_NEW_IMAGE\n");
  img->data = mlx_get_data_addr
    (img->img_ptr, &img->bpp, &img->sizeline, &img->endian);
  if (img->data == NULL)
    my_error("ERROR MLX_GET_DATA_ADDR\n");
  WIN_Y = WIN_Y /2;
}

void	get_option(const char *name_opt, t_option *opt)
{
  char	*line;
  char	**tab;
  int	fd;

  fd = my_open(name_opt, O_RDONLY);
  line = get_next_line(fd);
  tab = my_str_to_wordtab(line);
  WIN_X = my_getnbr(tab[1]);
  line = get_next_line(fd);
  tab = my_str_to_wordtab(line);
  WIN_Y = my_getnbr(tab[1]);
  free(line);
  free(tab);
  my_close(fd);
  if ((((WIN_X < 100) || (WIN_X > 1920)) || ((WIN_Y < 100) || (WIN_Y > 1080)))
      && (fd != 0))
    {
      WIN_X = 500;
      WIN_Y = 500;
    }
}

void	get_map(char *file_map, t_map *map)
{
  int	fd;
  int	x;
  int	y;

  fd = my_open(file_map, O_RDONLY);
  y = 0;
  while (y < 300)
    {
      x = 0;
      while (x < 300)
	MAP[x++][y] = 0;
      y++;
    }
  get_map2(fd, map, 0, 0);
}

void	get_map2(int fd, t_map *map, int x, int y)
{
  char	*line;
  char	**tab;

  while ((line = get_next_line(fd)) && line[0] != '\0')
    {
      x = -1;
      tab = my_str_to_wordtab(line);
      while (tab[++x] != 0 && line != NULL && x < 300)
	{
	  if ((MAP[x][y] = my_getnbr(tab[x])) == -1)
	    {
	      POS_X = x;
	      POS_Y = y;
	    }
	}
      if (y == 0)
	MAX_X = x;
      if (map->max_x != x && x == 300)
        my_error("INVALIDE MAP\n");
      y++;
    }
  free(line);
  free(tab);
  MAX_Y = y;
}
