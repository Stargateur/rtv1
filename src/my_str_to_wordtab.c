/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/plasko_a/rendu/Piscine-C-Jour_08/ex_04
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Wed Oct  9 23:29:57 2013 Antoine Plaskowski
** Last update Thu Feb 27 09:01:18 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"

static int	my_nbr_word(const char *str)
{
  int		i;

  i = 0;
  while (*str != '\0')
    {
      while (*str == ' ' || *str == '\t')
	str++;
      if (*str != '\0')
	i++;
      while (*str != ' ' && *str != '\t' && *str != '\0')
	str++;
    }
  return (i + 1);
}

static int	my_len_word(const char *str)
{
  int		i;

  i = 0;
  while (str[i] != ' ' && *str != '\t' && str[i] != '\0')
    i++;
  return (i + 1);
}

char		**my_str_to_wordtab(const char *str)
{
  char		**tab;
  int		i;
  int		j;

  if (str == NULL)
    return (NULL);
  if ((tab = my_malloc(sizeof(char *) * my_nbr_word(str))) == NULL)
    return (NULL);
  i = 0;
  while (*str != '\0')
    {
      while (*str == ' ' || *str == '\t')
	str++;
      if (*str != '\0')
	{
	  if ((tab[i] = my_malloc(sizeof(char) * my_len_word(str))) == NULL)
	    return (NULL);
	  j = 0;
	  while (*str != ' ' && *str != '\t' && *str != '\0')
	    tab[i][j++] = *str++;
	  tab[i++][j] = '\0';
	}
    }
  tab[i] = NULL;
  return (tab);
}
