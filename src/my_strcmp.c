/*
** my_strcmp.c for my_strcmp in /home/plasko_a/rendu/Piscine-C-Jour_06/ex_05
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Mon Oct  7 14:55:18 2013 Antoine Plaskowski
** Last update Mon Dec 16 02:55:02 2013 Antoine Plaskowski
*/

#include	<stdlib.h>

int		my_strcmp(const char *s1, const char *s2)
{
  if (s1 == NULL || s2 == NULL)
    return (-1);
  while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
    {
      s1++;
      s2++;
    }
  return (*s1 - *s2);
}
