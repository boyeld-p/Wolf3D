/*
** my_str_to_wordtab.c for my_str_towordtab in /home/brahic_a/rendu/fdf/lib
** 
** Made by brahic
** Login   <brahic_a@epitech.net>
** 
** Started on  Sun Dec  8 06:44:52 2013 brahic
** Last update Sun Dec  8 13:07:29 2013 brahic
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int	count_words(char *line)
{
  int	i;
  int	nb_words;

  nb_words = 0;
  i = 0;
  while (line[i] != '\0')
    {
      while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')
	i = i + 1;
      if (line[i] != ' ' && line[i] !=  '\t' && line[i] != '\0')
	nb_words = nb_words + 1;
      while (line[i] != ' ' && line[i] !=  '\t' && line[i] != '\0')
	i = i + 1;
    }
  return (nb_words);
}

char	**my_str_to_wordtab(char *line)
{
  char	**tab;
  char	*ptr;
  int	nb_words;
  int	i;

  nb_words = count_words(line);
  tab = malloc(sizeof(char *) * (nb_words + 1) + my_strlen(line) + 1);
  if (tab == NULL)
    exit(1);
  ptr = (char *)tab;
  ptr += sizeof(char *) * (nb_words + 1);
  ptr = my_strcpy(ptr, line);
  i = 0;
  while (*ptr != '\0')
    {
      while ((*ptr == ' ' || *ptr == '\t') && *ptr != '\0')
	*ptr++ = '\0';
      if (*ptr != ' ' && *ptr != '\t' && *ptr != '\0')
	tab[i++] = ptr;
      while (*ptr != ' ' && *ptr != '\t' && *ptr != '\0')
	ptr += 1;
    }
  tab[i] = '\0';
  return (tab);
}
