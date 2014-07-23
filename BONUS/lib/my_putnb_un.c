/*
** my_putnb_un.c for my_putnb_un in /home/Spam/rendu/printf
**
** Made by Brahic
** Login   <Spam@epitech.net>
**
** Started on  Sun Nov 17 10:59:40 2013 Brahic
** Last update Sun Nov 17 13:39:40 2013 Brahic
*/

unsigned int	my_putchar(char c);

unsigned int	my_putnb_un(unsigned int nbr)
{
  unsigned int	n;
  unsigned int	cmp;

  cmp = 0;
  n = 1;
  while ((nbr / 10) >= 10)
    n = n * 10;
  n = n * 10;
  while (n >= 1)
    {
      cmp += my_putchar((nbr / n) + '0');
      nbr = nbr % n;
      n = n / 10;
    }
  return (cmp);
}
