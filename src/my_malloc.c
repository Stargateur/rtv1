/*
** my_malloc.c for my_malloc in /home/plasko_a/rendu/Piscine-C-lib/my
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Fri Nov 29 17:01:00 2013 Antoine Plaskowski
** Last update Thu Feb 27 15:38:24 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"

void		*my_malloc(unsigned long nbr_octet)
{
  void		*pt;

  if (nbr_octet == 0)
    my_putstr("Warning malloc of 0\n", 2);
  if ((pt = malloc(nbr_octet)) == NULL)
    {
      my_putstr("Insufficient memory\n", 2);
      exit(1);
    }
  return (pt);
}

void		*my_calloc(unsigned long nbr_octet)
{
  char		*pt;
  unsigned int	i;

  if (nbr_octet == 0)
    my_putstr("Warning calloc of 0\n", 2);
  if ((pt = malloc(nbr_octet)) == NULL)
    {
      my_putstr("Insufficient memory\n", 2);
      exit(1);
    }
  i = 0;
  while (i < nbr_octet)
    pt[i++] = 0;
  return (pt);
}
