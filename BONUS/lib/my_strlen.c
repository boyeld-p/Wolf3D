/*
** my_strlen.c for my_strlen in /home/Spam/Bistro
**
** Made by Brahic
** Login   <Spam@epitech.net>
**
** Started on  Wed Oct 30 17:42:47 2013 Brahic
** Last update Thu Oct 31 03:10:19 2013 Brahic
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i++]);
  return (i);
}
