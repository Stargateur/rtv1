/*
** my_rotation.c for my_rotation in /home/plasko_a/rendu/MUL_2013_rtv1
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon Mar  3 11:33:43 2014 Antoine Plaskowski
** Last update Mon Mar  3 13:29:44 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<math.h>
#include	"my_rtv1.h"

int		my_rotation_x(t_object *object,  int angle)
{
  double	cos_a;
  double	sin_a;

  if (object == NULL)
    return (1);
  object->rotation_x_degres = angle;
  angle = angle * MY_PI / 180;
  cos_a = cos(angle);
  sin_a = sin(angle);
  object->rotation_x->matrix[2][2] = cos_a;
  object->rotation_x->matrix[2][3] = -sin_a;
  object->rotation_x->matrix[3][2] = sin_a;
  object->rotation_x->matrix[2][3] = cos_a;
  return (0);
}

int		my_rotation_y(t_object *object, int angle)
{
  double	cos_a;
  double	sin_a;

  if (object == NULL)
    return (1);
  object->rotation_y_degres = angle;
  angle = angle * MY_PI / 180;
  cos_a = cos(angle);
  sin_a = sin(angle);
  object->rotation_y->matrix[1][1] = cos_a;
  object->rotation_y->matrix[1][3] = sin_a;
  object->rotation_y->matrix[3][1] = -sin_a;
  object->rotation_y->matrix[1][3] = cos_a;
  return (0);
}

int		my_rotation_z(t_object *object, int angle)
{
  double	cos_a;
  double	sin_a;

  if (object == NULL)
    return (1);
  object->rotation_z_degres = angle;
  angle = angle * MY_PI / 180;
  cos_a = cos(angle);
  sin_a = sin(angle);
  object->rotation_z->matrix[1][1] = cos_a;
  object->rotation_z->matrix[1][2] = -sin_a;
  object->rotation_z->matrix[2][1] = sin_a;
  object->rotation_z->matrix[2][2] = cos_a;
  return (0);
}
