/*
** my_strdup.c for my_strdup in /home/brahic_a/rendu/fdf/lib
** 
** Made by brahic
** Login   <brahic_a@epitech.net>
** 
** Started on  Wed Dec  4 12:47:52 2013 brahic
** Last update Wed Dec  4 12:48:35 2013 brahic
*/

#include <stdlib.h>
#include "my.h"

char    *my_strdup(char *str)
{
  char  *dest;

  dest = (char *)malloc(sizeof(char) * my_strlen(str) + 1);
  dest = my_strcpy(dest, str);
  dest[my_strlen(str)] = 0;
  return (dest);
}
