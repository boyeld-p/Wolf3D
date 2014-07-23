/*
** my_printf_fonc.c for my_printf_fonc in /home/Spam/rendu/printf
**
** Made by Brahic
** Login   <Spam@epitech.net>
**
** Started on  Sun Nov 17 03:59:05 2013 Brahic
** Last update Sun Nov 17 12:14:31 2013 Brahic
*/

#include <stdarg.h>
#include "my.h"

unsigned int		my_printf_p(va_list *ap)
{
  unsigned long		nb;
  unsigned int		cmp;

  cmp = 0;
  nb = va_arg(*ap, unsigned long);
  cmp += my_putstr("0x");
  cmp += my_putnb_base_un(nb, "0123456789abcdef");
  return (cmp);
}

unsigned int		my_printf_b(va_list *ap)
{
  unsigned long		nb;
  unsigned int		cmp;

  cmp = 0;
  nb = va_arg(*ap, unsigned long);
  cmp += my_putnb_base_un(nb, "01");
  return (cmp);
}
