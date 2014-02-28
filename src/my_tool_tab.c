/*
** my_tool_tab.c for my_tool_tab in /home/plasko_a/rendu/PSU_2013_minishell1/src
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Dec 15 23:36:39 2013 Antoine Plaskowski
** Last update Thu Feb 27 09:04:54 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"

void		my_free_tab(char **tab)
{
  int		i;

  if (tab != NULL)
    {
      i = 0;
      while (tab[i] != NULL)
	free(tab[i++]);
      free(tab);
    }
}

char		**my_cpy_tab(char **tab)
{
  char		**my_new_tab;
  int		i;

  if (tab == NULL)
    return (NULL);
  i = 0;
  while (tab[i] != NULL)
    i++;
  if ((my_new_tab = my_malloc(sizeof(char *) * (i + 1))) == NULL)
    return (NULL);
  i = 0;
  while (tab[i] != NULL)
    {
      if ((my_new_tab[i] = my_strdup(tab[i])) == NULL)
	return (NULL);
      i++;
    }
  my_new_tab[i] = NULL;
  return (my_new_tab);
}

int		my_aff_tab(char **tab, const int fd)
{
  if (tab == NULL)
    return (1);
  while (*tab != NULL)
    {
      my_putstr(*tab++, fd);
      my_putchar(' ', fd);
    }
  my_putchar('\n', fd);
  return (0);
}

int		my_len_tab(char **tab)
{
  int		i;

  if (tab == NULL)
    return (1);
  i = 0;
  while (tab[i] != NULL)
    i++;
  return (i);
}
