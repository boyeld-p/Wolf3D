/*
** cad.c for cadran in
**
** Made by Brahic
** Login   <Spam@epitech.net>
**
** Started on  Thu Nov 14 23:12:29 2013 Brahic
** Last update Wed Dec  4 09:41:39 2013 brahic
*/

#include "my_igraph.h"

void		cad1(t_param *param, t_seg *seg)
{
  if (seg->dy != 0)
    {
      if (seg->dy > 0)
	{
	  if (seg->dx >= seg->dy)
	    octant1(param, seg);
	  else
	    octant2(param, seg);
	}
      else
	{
	  if (seg->dx >= -1 * seg->dy)
	    octant8(param, seg);
	  else
	    octant7(param, seg);
	}
    }
  else
    seg_x1(param, seg);
}

void		cad2(t_param *param, t_seg *seg)
{
  if (seg->dy != 0)
    {
      if (seg->dy > 0)
	{
	  if (-1 * seg->dx >= seg->dy)
	    octant4(param, seg);
	  else
	    octant3(param, seg);
	}
      else
	{
	  if (seg->dx <= seg->dy)
	    octant5(param, seg);
	  else
	    octant6(param, seg);
	}
    }
  else
    seg_x2(param, seg);
}

void		honz(t_param *param, t_seg *seg)
{
  if (seg->dy != 0)
    {
      if (seg->dy > 0)
	seg_y1(param, seg);
      else
	seg_y2(param, seg);
    }
}
