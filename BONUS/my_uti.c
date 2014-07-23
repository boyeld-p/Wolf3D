/*
** my_uti2.c for my_uti2.c in /home/brahic_a/rendu/fdf
** 
** Made by brahic
** Login   <brahic_a@epitech.net>
** 
** Started on  Sun Dec  8 05:45:45 2013 brahic
** Last update Sun Jan 12 20:55:25 2014 brahic
*/

#include "mlx.h"
#include "my_igraph.h"
#include "my.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include <stdio.h>

void	my_raycast(t_option *opt, t_map *map, t_ray *ray, t_param *param)
{
  int	x;

  x = 0;
  RAY_X = 0.5;
  while (x < WIN_X)
    {
      DIST = 0;
      RAY_Y = ((0.5 * ((WIN_X * 0.5) - x)) / WIN_X);
      RAY_X_PRI = RAY_X * cos(ANGLE) - RAY_Y * sin(ANGLE) + POS_X;
      RAY_Y_PRI = RAY_X * sin(ANGLE) + RAY_Y * cos(ANGLE) + POS_Y;
      find_wall(map, ray);
      if (COEF > 1 && COEF < 50)
	draw_wall(param, ray, opt, x);
      else
	draw_wall_error(param, opt, x);
      x++;
    }
}

void	draw_wall_error(t_param *param, t_option *opt, int x)
{
  draw_y(x, 0, WIN_Y, 0x0099CC, param);
  draw_y(x, WIN_Y, WIN_Y + WIN_Y, 0x006600, param);
}

void	draw_wall(t_param *param, t_ray *ray, t_option *opt, int x)
{
  NB_PIX_WALL = ((WIN_Y + WIN_Y) / COEF) / 2;
  draw_y(x, 0, WIN_Y - NB_PIX_WALL, 0x0099CC, param);
  if (ray->last_find_x == (int) FIND_X && ray->last_find_y == (int) FIND_Y)
    {
      if ((FIND_X - ((int)FIND_X)) < 0.01 && (FIND_Y - ((int)FIND_Y)) < 0.992)
	draw_y(x, WIN_Y - NB_PIX_WALL,
	       WIN_Y - NB_PIX_WALL + NB_PIX_WALL + NB_PIX_WALL , 0xF7230C, param);
      if ((FIND_Y - ((int)FIND_Y)) > 0.99 && (FIND_X - ((int)FIND_X) < 0.992))
	draw_y(x, WIN_Y - NB_PIX_WALL,
	       WIN_Y - NB_PIX_WALL + NB_PIX_WALL + NB_PIX_WALL , 0xFFFF00, param);
      if ((FIND_X - ((int)FIND_X)) > 0.99 && (FIND_Y - ((int)FIND_Y)) > 0.01)
	draw_y(x, WIN_Y - NB_PIX_WALL,
	       WIN_Y - NB_PIX_WALL + NB_PIX_WALL + NB_PIX_WALL , 0xF400A8, param);
      if ((FIND_Y - ((int)FIND_Y)) < 0.01 && (FIND_X - ((int)FIND_X) > 0.01))
	draw_y(x, WIN_Y - NB_PIX_WALL,
	       WIN_Y - NB_PIX_WALL + NB_PIX_WALL + NB_PIX_WALL , 0xFFFFFF, param);
    }
  else
    draw_y(x, WIN_Y - NB_PIX_WALL + 1,
	   WIN_Y - NB_PIX_WALL + NB_PIX_WALL + NB_PIX_WALL - 1 , 0x000000, param);
  draw_y(x, WIN_Y - NB_PIX_WALL + NB_PIX_WALL + NB_PIX_WALL,
	 WIN_Y + WIN_Y, 0x006600, param);
  ray->last_find_x = (int) FIND_X;
  ray->last_find_y = (int) FIND_Y;
}
void	find_wall(t_map *map, t_ray *ray)
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
  if (COEF < 50)
    DIST = sqrt(pow((FIND_X - POS_X), 2) + pow((FIND_Y - POS_Y), 2));
}

void	draw_y(int x, int drawStart, int drawEnd, int color, t_param *param)
{
  int	y;

  y = drawStart;
  while (y < drawEnd)
    my_put_pix_img(param, x, y++, color);
}
