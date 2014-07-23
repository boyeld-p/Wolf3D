/*
** my_putchar.c for My put char in 
** 
** Made by Brahic
** Login   <Spam@epitech.net>
** 
** Started on  Wed Oct  2 11:32:47 2013 Brahic
** Last update Sun Nov 17 12:31:02 2013 Brahic
*/

#include <unistd.h>

unsigned int my_putchar(int a)
{
  write(1, &a, 1);
  return (1);
}
