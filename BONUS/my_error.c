/*
** my_errorfdf.c for my_error in /home/brahic_a/rendu/fdf
** 
** Made by brahic
** Login   <brahic_a@epitech.net>
** 
** Started on  Sun Dec  8 15:10:11 2013 brahic
** Last update Tue Dec 17 09:58:15 2013 brahic
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "my_igraph.h"

void	my_error(const char *str)
{
  my_printf("%s", str);
  exit(1);
}
