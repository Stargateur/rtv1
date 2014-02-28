/*
** my_load_scene.c for my_load_scene in /home/plasko_a/rendu/MUL_2013_rtv1
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Feb 27 08:19:50 2014 Antoine Plaskowski
** Last update Fri Feb 28 17:28:00 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_rtv1.h"
#include	"my_open.h"
#include	"my_get_next_line.h"
#include	"my_str.h"
#include	"my_tool_tab.h"

static t_object	*my_found_eye(t_rtv1 *rtv1)
{
  t_object	*eye;
  t_object	*tmp;

  eye = NULL;
  tmp = rtv1->object;
  while (tmp != NULL && eye == NULL)
    if (my_strcmp(tmp->name, "eye") == 0)
      {
	if ((eye = my_cpy_object(tmp)) == NULL)
	  return (NULL);
	rtv1->object = my_remove_object(tmp);
      }
    else
      tmp = tmp->next;
  return (eye);
}

static int	my_create_object(t_rtv1 *rtv1, const int fd)
{
  char		**wordtab;
  char		*nextline;

  while ((nextline = my_get_next_line(fd)) != NULL)
    {
      if ((wordtab = my_str_to_wordtab(nextline)) == NULL)
	return (1);
      free(nextline);
      if ((rtv1->object = my_new_object(rtv1->object, wordtab)) == NULL)
	return (1);
      my_free_tab(wordtab);
    }
  if (rtv1->object != NULL)
    while (rtv1->object->prev != NULL)
      rtv1->object = rtv1->object->prev;
  return (0);
}

int		my_load_scene(t_rtv1 *rtv1, char *path)
{
  int		fd;

  if (rtv1 == NULL || path == NULL)
    return (1);
  if ((fd = my_open_rdonly(path)) == -1)
    return (1);
  if (my_create_object(rtv1, fd))
    return (1);
  if ((rtv1->eye = my_found_eye(rtv1)) == NULL)
    {
      my_putstr("No eye... add it to scene file !\n", 2);
      return (1);
    }
  if (rtv1->object != NULL)
    while (rtv1->object->prev != NULL)
      rtv1->object = rtv1->object->prev;
  if (my_found_eye(rtv1) != NULL)
    {
      my_putstr("there are more than 1 eye in the scene !\n", 2);
      return (1);
    }
  return (0);
}
