/*
** my_opendir.c for my_opendir in /home/brahic_a/CPROG/PSU_2013_my_ls
** 
** Made by brahic
** Login   <brahic_a@epitech.net>
** 
** Started on  Fri Nov 29 01:35:53 2013 brahic
** Last update Sun Dec  8 06:00:58 2013 brahic
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

DIR		*my_opendir(const char *dir)
{
  DIR		*rep = NULL;

  if ((rep = opendir(dir)) == NULL)
    {
      perror("OPENDIR ERROR ");
      exit(EXIT_FAILURE);
    }
  return (rep);
}

int		my_closedir(DIR *rep)
{
  if (closedir(rep) == -1)
    {
      perror("CLOSEDIR ERROR ");
      exit(EXIT_FAILURE);
    }
  return (0);
}

struct dirent	*my_readdir(DIR *rep)
{
  struct dirent	*file = NULL;
  errno = 0;
  file = readdir(rep);
  if (errno)
    {
      perror("READDIR ERROR ");
      exit(EXIT_FAILURE);
    }
  return (file);
}

int		my_stat(const char *file_name, struct stat *buff)
{
  if ((stat(file_name, buff)) != 0)
    {
      perror("STAT ERROR ");
      exit(EXIT_FAILURE);
    }
  return (0);
}
