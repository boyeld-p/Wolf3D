/*
** my_putnbr_base.c for my_putnbr_base in /home/Spam/rendu/printf
**
** Made by Brahic
** Login   <Spam@epitech.net>
**
** Started on  Sun Nov 17 08:59:26 2013 Brahic
** Last update Sun Nov 17 16:39:35 2013 Brahic
*/

unsigned int		my_putchar(char c);

unsigned int	neg_base(int nbr)
{
  if (nbr == -2147483648)
    nbr++;
  nbr *= -1;
  return (nbr);
}

unsigned int	my_putnbr_base(int nbr, char *base)
{
  unsigned int	i;
  int		n;
  unsigned int	cmp;

  i = 0;
  cmp = 0;
  n = 1;
  while (base[i] != '\0')
    i++;
  if (nbr < 0)
    {
      neg_base(nbr);
      cmp += my_putchar('-');
    }
  while (n < nbr)
    n = n * i;
  if (n != nbr)
    n = n / i;
  while (n >= 1)
    {
      cmp += my_putchar(base[nbr / n]);
      nbr = nbr % n;
      n = n / i;
    }
  return (cmp);
}
