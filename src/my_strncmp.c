/*
** my_strncmp.c for my_strncmp in /home/plasko_a/rendu/Piscine-C-Jour_06/ex_05
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Mon Oct  7 14:50:07 2013 Antoine Plaskowski
** Last update Wed Feb  5 10:51:57 2014 Antoine Plaskowski
*/

#include	<stdlib.h>

long		my_strncmp(char *s1, char *s2, long n)
{
  long		i;

  if (s1 == NULL || s2 == NULL)
    return (0);
  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n)
    i++;
  if (i < n)
    return (*(s1 + i) - *(s2 + i));
  return (0);
}
