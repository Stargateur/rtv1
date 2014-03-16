/*
** my_load_scene.c for my_load_scene in /home/plasko_a/rendu/MUL_2013_rtv1
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Feb 27 08:19:50 2014 Antoine Plaskowski
** Last update Sun Mar 16 12:14:12 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_rtv1.h"
#include	"my_open.h"
#include	"my_get_next_line.h"
#include	"my_str.h"
#include	"my_tool_tab.h"

static int	my_matrix_eye(t_object *object)
{
  t_matrix	*tmp;

  if ((tmp = my_new_matrix(4, 1)) == NULL)
    return (1);
  tmp->matrix[3][0] = 1;
  while (object != NULL)
    {
      if ((object->eye = my_mul_matrix(object->trans, tmp)) == NULL)
	return (1);
      object = object->next;
    }
  my_free_matrix(tmp);
  return (0);
}

static int	my_matrix_trans(t_object *eye, t_object *object)
{
  t_matrix      *matrix;
  t_matrix      *tmp;

  while (object != NULL)
    {
      if ((matrix = my_mul_matrix(eye->ro, object->ro_opo)) == NULL)
	return (1);
      if ((tmp = my_mul_matrix(matrix, eye->po)) == NULL)
	return (1);
      my_free_matrix(matrix);
      if ((matrix = my_mul_matrix(tmp, object->po_opo)) == NULL)
	return (1);
      my_free_matrix(tmp);
      object->trans = matrix;
      object = object->next;
    }
  return (0);
}

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
  if (my_matrix_trans(rtv1->eye, rtv1->object) || my_matrix_eye(rtv1->object) || my_light(rtv1))
    return (1);
  return (0);
}
