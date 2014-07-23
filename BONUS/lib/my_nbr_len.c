/*
** my_nbr_len.c for my_nbr_len in /home/Spam/rendu/printf
**
** Made by Brahic
** Login   <Spam@epitech.net>
**
** Started on  Sun Nov 17 04:24:05 2013 Brahic
** Last update Sun Nov 17 13:14:49 2013 Brahic
*/

unsigned int     my_nbr_len(int nbr)
{
  unsigned int   i;
  unsigned int   k;

  i = 1;
  k = 1;
  while ((nbr / i) >= 10)
    {
      i = i * 10;
      k++;
    }
  return (k);
}

unsigned int     my_nbr_un_len(unsigned int nbr)
{
  unsigned int   i;
  unsigned int   k;

  i = 1;
  k = 1;
  while ((nbr / i) >= 10)
    {
      i = i * 10;
      k++;
    }
  return (k);
}

