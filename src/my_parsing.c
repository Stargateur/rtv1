/*
** my_parsing.c for my_parsing in /home/plasko_a/rendu/MUL_2013_rtv1
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Feb 27 08:19:50 2014 Antoine Plaskowski
** Last update Fri Feb 28 09:14:13 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_rtv1.h"
#include	"my_open.h"
#include	"my_get_next_line.h"
#include	"my_str.h"
#include	"my_tool_tab.h"

static t_object	*my_found_eye(t_object *object)
{
  t_object	*eye;
}

int		my_parsing(t_rtv1 *rtv1, char *path)
{
  char		**wordtab;
  char		*nextline;
  int		fd;

  if (rtv1 == NULL || path == NULL)
    return (1);
  if ((fd = my_open_rdonly(path)) == -1)
    return (1);
  while ((nextline = my_get_next_line(fd)) != NULL)
    {
      if ((wordtab = my_str_to_wordtab(nextline)) == NULL)
	return (1);
      free(nextline);
      if ((rtv1->object = my_new_object(rtv1->object, wordtab)) == NULL)
	return (1);
      my_free_tab(wordtab);
    }
  return (0);
}
