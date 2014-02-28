/*
** my_tool_object.c for my_tool_object in /home/plasko_a/rendu/MUL_2013_rtv1
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Feb 27 17:42:43 2014 Antoine Plaskowski
** Last update Fri Feb 28 09:37:12 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_rtv1.h"
#include	"my_str.h"

int		my_aff_all_object(t_object *object)
{
  while (object != NULL)
    {
      my_aff_object(object);
      object = object->next;
    }
  return (0);
}

int		my_aff_object(t_object *object)
{
  if (object == NULL)
    return (1);
  my_putstr("object = ", 1);
  my_putstr(object->name, 1);
  my_putstr("\nposition_x = ", 1);
  my_putnbr(object->position->matrix[0][0], 1);
  my_putstr("\nposition_y = ", 1);
  my_putnbr(object->position->matrix[1][0], 1);
  my_putstr("\nposition_y = ", 1);
  my_putnbr(object->position->matrix[2][0], 1);
  my_putstr("\nrotation_x = ", 1);
  my_putnbr(object->rotation_x, 1);
  my_putstr("\nrotation_y = ", 1);
  my_putnbr(object->rotation_y, 1);
  my_putstr("\nrotation_z = ", 1);
  my_putnbr(object->rotation_z, 1);
  my_putstr("\nrayon = ", 1);
  my_putnbr(object->rayon, 1);
  my_putstr("\ncolor = ", 1);
  my_putnbr_base(object->color.color, "0123456789ABCDEF", 1);
  my_putchar('\n', 1);
  return (1);
}

t_object	*my_remove_object(t_object *object)
{
  t_object	*tmp;

  if (object == NULL)
    return (NULL);
  if (object->prev != NULL)
    {
      object->prev->next = object->next;
      tmp = object->prev;
    }
  if (object->next != NULL)
    {
      object->next->prev = object->prev;
      tmp = object->next;
    }
  else
    tmp = NULL;
  my_free_matrix(object->position);
  free(object->name);
  free(object);
  return (tmp);
}

t_object	*my_insert_object(t_object *object, t_object *new_object)
{
  if (object == NULL || new_object == NULL)
    return (new_object);
  if (object->prev != NULL)
    {
      object->prev->next = new_object;
      new_object->prev = object->prev;
    }
  object->prev = new_object;
  new_object->next = object;
  return (new_object);
}
