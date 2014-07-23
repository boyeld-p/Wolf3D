/*
** my_putpix_img.c for my_putpix_img in /home/brahic_a/rendu/MUL_2013_wolf3d
** 
** Made by brahic
** Login   <brahic_a@epitech.net>
** 
** Started on  Tue Dec 17 10:58:55 2013 brahic
** Last update Sun Jan 12 18:30:56 2014 brahic
*/

#include "my_igraph.h"
#include "mlx.h"
#include <stdio.h>

void	my_put_pix_img(t_param *param, int x, int y, int color)
{
  unsigned int	img_color;
  unsigned char r;
  unsigned char g;
  unsigned char b;

  img_color = mlx_get_color_value(param->mlx_ptr, color);
  r = ((img_color & 0xFF0000) >> 16);
  g = ((img_color & 0xFF00) >> 8);
  b = img_color & 0xFF;
  param->pt_img->data[(y * param->pt_img->sizeline)
		      + (x * param->pt_img->bpp) / 8 ] = b;
  param->pt_img->data[(y * param->pt_img->sizeline)
		      + ((x * param->pt_img->bpp) / 8) + 1] = g;
  param->pt_img->data[(y * param->pt_img->sizeline)
		      + ((x * param->pt_img->bpp) / 8) + 2] = r;
}
