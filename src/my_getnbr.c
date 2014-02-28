/*
** my_getnbr.c for my_getnbr in /home/plasko_a/rendu/Piscine-C-Jour_04
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Thu Oct  3 13:27:41 2013 Antoine Plaskowski
** Last update Thu Feb 27 18:13:33 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"

int		my_getnbr(const char *str)
{
  int		sign;
  int		nbr;

  if (str == NULL)
    return (0);
  sign = 1;
  while (*str != '\0' && (*str == '-' || *str == '+'))
    if (*str++ == '-')
      sign *= -1;
  while (*str == '0')
    str++;
  nbr = 0;
  if (sign > 0)
    while (*str >= '0' && *str <= '9')
      nbr = nbr * 10 + (*str++ - '0');
  else
    while (*str >= '0' && *str <= '9')
      nbr = nbr * 10 - (*str++ - '0');
  return (nbr);
}
