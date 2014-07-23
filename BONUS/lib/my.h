/*
** my.h for my.h in 
** 
** Made by Brahic
** Login   <Spam@epitech.net>
** 
** Started on  Wed Oct  9 11:04:46 2013 Brahic
** Last update Sun Dec  8 06:01:33 2013 brahic
*/

#ifndef MY_H_
# define MY_H_

#include <stdarg.h>
#include <dirent.h>
#include <sys/stat.h>

typedef struct s_type
{
  char		type;
  unsigned int	(*ptr_fonc)(va_list *);
}t_type;

int			my_getnbr(char *str);
unsigned int		my_putchar(int c);
unsigned int		my_nbr_len(int nbr);
unsigned int		my_nbr_un_len(unsigned int nbr);
unsigned int		my_putnbr_base(int nbr, char *base);
unsigned int		my_putnb_base_un(unsigned int nbr, char *base);
unsigned int		my_putnb_un(unsigned int nbr);
unsigned int		my_put_nbr(int nb);
unsigned int		my_putstr(char *str);
unsigned int		my_strlen(char *str);
char			*my_strcpy(char *dest, char *src);
char			*my_strdup(char *str);
char			**my_str_to_wordtab(char *str);

unsigned int		my_printf_pc(va_list *ap);
unsigned int		my_printf_c(va_list *ap);
unsigned int		my_printf_d(va_list *ap);
unsigned int		my_printf_s(va_list *ap);
unsigned int		my_printf_S(va_list *ap);
unsigned int		my_printf_o(va_list *ap);
unsigned int		my_printf_u(va_list *ap);
unsigned int		my_printf_x(va_list *ap);
unsigned int		my_printf_X(va_list *ap);
unsigned int		my_printf_p(va_list *ap);
unsigned int		my_printf_b(va_list *ap);
unsigned int		my_printf(char *,...);

DIR			*my_opendir(const char *dir);
int			my_closedir(DIR *rep);
struct dirent		*my_readdir(DIR *rep);
int			my_stat(const char *file_name, struct stat *buff);
int			my_open(const char *path, int oflag);
int			my_close(int);

#ifndef         __GET_NEXT_LINE_H__
#define        __GET_NEXT_LINE_H__

#define       SIZE    3400

char    *get_next_line(const int);

#endif


#endif /* !MY_H_ */
