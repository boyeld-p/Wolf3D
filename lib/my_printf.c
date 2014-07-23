/*
** my_printf.c for my_printf in /home/Spam/rendu/printf
**
** Made by Brahic
** Login   <Spam@epitech.net>
**
** Started on  Tue Nov 12 11:00:04 2013 Brahic
** Last update Sun Nov 17 17:54:24 2013 Brahic
*/

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "my.h"

t_type	tab_type[] =
  {
    {'%', &my_printf_pc},
    {'c', &my_printf_c},
    {'d', &my_printf_d},
    {'i', &my_printf_d},
    {'s', &my_printf_s},
    {'S', &my_printf_S},
    {'o', &my_printf_o},
    {'u', &my_printf_u},
    {'x', &my_printf_x},
    {'X', &my_printf_X},
    {'p', &my_printf_p},
    {'b', &my_printf_b},
    {0, NULL},
  };

unsigned int		fonc_check(char *txt, va_list *ap, unsigned int i)
{
  unsigned int		k;
  unsigned int		len;

  k = 0;
  len = 0;
  i++;
  while (tab_type[k].type != txt[i] && tab_type[k].type)
    k++;
  if (tab_type[k].ptr_fonc == NULL)
    {
      len += my_putchar('%');
      len += my_putchar(txt[i]);
    }
  else
    len += (*tab_type[k].ptr_fonc)(ap);
  return (len - 1);
}

unsigned int		my_printf(char *txt, ...)
{
  unsigned int		i;
  unsigned int		len;
  va_list		ap;

  va_start(ap, txt);
  i = 0;
  len = 0;
  while (txt[i])
    {
      if (txt[i] == '%')
	{
	  len += fonc_check(txt, &ap, i);
	  i++;
	}
      else
	write(1, &txt[i], 1);
      i++;
    }
  va_end(ap);
  return (i + len - 1);
}
