/*
** my_putnbr_base.c for my_putnbr_base in /home/plasko_a/rendu/Piscine-C-Jour_06/ex_15
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Tue Oct  8 16:45:05 2013 Antoine Plaskowski
** Last update Thu Feb 27 18:21:33 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"

int		my_putnbr_base(int nb, const char *base, const int fd)
{
  if (base == NULL || my_strlen(base) < 2)
    return (1);
  if (nb / my_strlen(base) != 0)
    my_putnbr_base(nb / my_strlen(base), base, fd);
  else if (nb < 0)
    my_putchar('-', fd);
  if ((nb %= my_strlen(base)) < 0)
    nb *= -1;
  my_putchar(base[nb], fd);
  return (0);
}
