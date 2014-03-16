/*
** my_tool_object.c for my_tool_object in /home/plasko_a/rendu/MUL_2013_rtv1
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Feb 27 17:42:43 2014 Antoine Plaskowski
** Last update Sun Mar 16 12:33:18 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<stdio.h>
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
  printf("object = %s\nrayon = %f\ncolor = %x\n", object->name, object->rayon, object->color.color);
  printf("trans=\n");
  my_aff_matrix(object->trans);
  printf("eye=\n");
  my_aff_matrix(object->eye);
  printf("ro=\n");
  my_aff_matrix(object->ro);
  printf("ro_opo=\n");
  my_aff_matrix(object->ro_opo);
  printf("po=\n");
  my_aff_matrix(object->po);
  printf("po_opo=\n");
  my_aff_matrix(object->po_opo);
  my_putchar('\n', 1);
  return (1);
}

static void	my_free_object(t_object *object)
{
  if (object != NULL)
    {
      my_free_matrix(object->eye);
      my_free_matrix(object->trans);
      my_free_matrix(object->po);
      my_free_matrix(object->po_opo);
      my_free_matrix(object->ro);
      my_free_matrix(object->ro_opo);
      free(object->name);
      free(object);
    }
}

t_object	*my_remove_object(t_object *object)
{
  t_object	*tmp;

  if (object == NULL)
    return (NULL);
  tmp = NULL;
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
  my_free_object(object);
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

t_object	*my_cpy_object(t_object *object)
{
  t_object	*cpy;

  if (object == NULL)
    return (NULL);
  if ((cpy = my_malloc(sizeof(t_object))) == NULL)
    return (NULL);
  if ((cpy->name = my_strdup(object->name)) == NULL)
    return (NULL);
  cpy->trans = my_cpy_matrix(object->trans);
  cpy->eye = my_cpy_matrix(object->eye);
  if ((cpy->po = my_cpy_matrix(object->po)) == NULL ||
      (cpy->po_opo = my_cpy_matrix(object->po_opo)) == NULL ||
      (cpy->ro = my_cpy_matrix(object->ro)) == NULL ||
      (cpy->ro_opo = my_cpy_matrix(object->ro_opo)) == NULL)
    return (NULL);
  cpy->degres_x = object->degres_x;
  cpy->degres_y = object->degres_y;
  cpy->degres_z = object->degres_z;
  cpy->rayon = object->rayon;
  cpy->color = object->color;
  cpy->prev = NULL;
  cpy->next = NULL;
  return (cpy);
}

int		my_len_object(t_object *object)
{
  int		i;

  i = 0;
  while (object != NULL)
    {
      i++;
      object = object->next;
    }
  return (i);
}
