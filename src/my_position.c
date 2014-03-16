/*
** my_position.c for my_position in /home/plasko_a/rendu/MUL_2013_rtv1
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon Mar  3 18:23:00 2014 Antoine Plaskowski
** Last update Sun Mar 16 11:49:14 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_rtv1.h"
#include	"my_str.h"

int		my_position_x(t_object *object, int nb)
{
  if (object == NULL)
    return (1);
  object->po->matrix[0][3] = nb;
  object->po_opo->matrix[0][3] = -nb;
  return (0);
}

int		my_position_y(t_object *object, int nb)
{
  if (object == NULL)
    return (1);
  object->po->matrix[1][3] = nb;
  object->po_opo->matrix[1][3] = -nb;
  return (0);
}

int		my_position_z(t_object *object, int nb)
{
  if (object == NULL)
    return (1);
  object->po->matrix[2][3] = nb;
  object->po_opo->matrix[2][3] = -nb;
  return (0);
}
