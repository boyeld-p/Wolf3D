/*
** my_printf_fonc.c for my_printf_fonc in /home/Spam/rendu/printf
**
** Made by Brahic
** Login   <Spam@epitech.net>
**
** Started on  Sun Nov 17 03:59:05 2013 Brahic
** Last update Sun Nov 17 17:53:17 2013 Brahic
*/

#include <stdarg.h>
#include "my.h"

unsigned int		my_printf_pc(va_list *ap)
{
  (void) ap;
  my_putchar('%');
  return (0);
}

unsigned int		my_printf_o(va_list *ap)
{
  unsigned int		nb;

  nb = va_arg(*ap, unsigned int);
  return (my_putnb_base_un(nb, "01234567"));
}

unsigned int		my_printf_u(va_list *ap)
{
  unsigned int		nb;

  nb = va_arg(*ap, unsigned int);
  return (my_putnb_un(nb));
}

unsigned int		my_printf_x(va_list *ap)
{
  unsigned int		nb;

  nb = va_arg(*ap, unsigned int);
  return (my_putnb_base_un(nb, "0123456789abcdef"));
}

unsigned int		my_printf_X(va_list *ap)
{
  unsigned int		nb;

  nb = va_arg(*ap, unsigned int);
  return (my_putnb_base_un(nb, "0123456789ABCDEF"));
}
