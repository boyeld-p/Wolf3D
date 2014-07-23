/*
** my_getnbr.c for getnbr in /home/brahic_a/rendu/fdf
** 
** Made by brahic
** Login   <brahic_a@epitech.net>
** 
** Started on  Wed Dec  4 09:27:15 2013 brahic
** Last update Sun Dec  8 08:09:09 2013 brahic
*/

#define BOOL int
#define TRUE 1
#define FALSE 0
#define IS_DIGIT(c) (c >= '0' && c <= '9' ? TRUE : FALSE)
#define IS_NEG_OR_POS(c) ((c == '-' || c == '+') ? TRUE : FALSE)

int	my_strlen(char *str);

int	my_getnbr_getval(char *str)
{
  int	power;
  int	nb;
  int	i;

  power = 1;
  nb = str[0] - 48;
  i = 0;

  while (i < my_strlen(str) - 1 && IS_DIGIT(str[i + 1]))
    {
      power *= 10;
      i += 1;
    }
  return (nb * power);
}

int	my_getnbr(char *str)
{
  if (str[0] != '\0' && IS_NEG_OR_POS(str[0]))
    {
      return (str[0] == '-' ?
	      -1 * my_getnbr(&str[1]) : 1 * my_getnbr(&str[1]));
    }
  else if (IS_DIGIT(str[0]))
    {
      return (my_getnbr_getval(str) + my_getnbr(&str[1]));
    }
  else
    {
      return (0);
    }
}
