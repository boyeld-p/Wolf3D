/*
** my_dir2.c for my_dir2 in /home/brahic_a/rendu/fdf/lib
** 
** Made by brahic
** Login   <brahic_a@epitech.net>
** 
** Started on  Sun Dec  8 05:59:29 2013 brahic
** Last update Sun Dec  8 06:02:22 2013 brahic
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include "my.h"

int	my_open(const char *path, int oflag)
{
  int	fd;

  if ((fd = open(path, oflag)) == -1)
    {
      perror("OPEN ERROR ");
      exit(EXIT_FAILURE);
    }
  return (fd);
}

int	my_close(int fildes)
{
  if (close(fildes) ==  -1)
    {
      perror("CLOSE ERROR ");
      exit(EXIT_FAILURE);
    }
  return (0);
}
