/*
** my_strdup.c for my_strdup in /home/plasko_a/rendu/Piscine-C-lib/my
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Fri Nov 29 16:25:29 2013 Antoine Plaskowski
** Last update Sun Dec 15 16:40:23 2013 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"

char		*my_strdup(const char *str)
{
  char		*cpy;

  if (str == NULL)
    return (NULL);
  if ((cpy = my_malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  if (my_strcpy(cpy, str))
    {
      free(cpy);
      return (NULL);
    }
  return (cpy);
}
