/*
** my_putnb_base_un.c for my_putnbr_base_un in /home/Spam/rendu/printf
** 
** Made by Brahic
** Login   <Spam@epitech.net>
** 
** Started on  Sun Nov 17 09:45:05 2013 Brahic
** Last update Sun Nov 17 12:18:19 2013 Brahic
*/

unsigned int		my_putchar(char c);

unsigned int		my_putnb_base_un(unsigned int nbr, char *base)
{
  unsigned int		i;
  unsigned long int	n;
  unsigned int		cmp;

  i = 0;
  cmp = 0;
  while (base[i] != '\0')
    i = i + 1;
  n = 1;
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
