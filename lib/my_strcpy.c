/*
** my_strcpy.c for my_strcpy in /home/brahic_a/rendu/fdf/lib
** 
** Made by brahic
** Login   <brahic_a@epitech.net>
** 
** Started on  Wed Dec  4 12:50:06 2013 brahic
** Last update Wed Dec  4 12:53:05 2013 brahic
*/

#include "my.h"

char    *my_strcpy(char *dest, char *src)
{
  int   i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
