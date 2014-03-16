/*
** my_rotation.c for my_rotation in /home/plasko_a/rendu/MUL_2013_rtv1
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon Mar  3 11:33:43 2014 Antoine Plaskowski
** Last update Sun Mar 16 20:06:58 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<math.h>
#include	"my_rtv1.h"
#include	"my_str.h"

static int	my_rotation(t_object *object, t_matrix *m, t_matrix *m_opo)
{
  t_matrix	*tmp;

  tmp = object->ro;
  if ((object->ro = my_mul_matrix(object->ro, m)) == NULL)
    return (1);
  my_free_matrix(tmp);
  my_free_matrix(m);
  tmp = object->ro_opo;
  if ((object->ro_opo = my_mul_matrix(object->ro_opo, m_opo)) == NULL)
    return (1);
  my_free_matrix(tmp);
  my_free_matrix(m_opo);
  return (0);
}

int		my_rotation_x(t_object *object, int angle)
{
  t_matrix	*matrix;
  t_matrix	*matrix_opo;
  double	cos_a;
  double	sin_a;

  if (object == NULL || (matrix = my_identity(4)) == NULL ||
      (matrix_opo = my_identity(4)) == NULL)
    return (1);
  object->degres_x = angle;
  cos_a = cos(angle * MY_PI / 180);
  sin_a = sin(angle * MY_PI / 180);
  matrix->matrix[1][1] = cos_a;
  matrix->matrix[1][2] = -sin_a;
  matrix->matrix[2][1] = sin_a;
  matrix->matrix[2][2] = cos_a;
  cos_a = cos(-angle * MY_PI / 180);
  sin_a = sin(-angle * MY_PI / 180);
  matrix_opo->matrix[1][1] = cos_a;
  matrix_opo->matrix[1][2] = -sin_a;
  matrix_opo->matrix[2][1] = sin_a;
  matrix_opo->matrix[2][2] = cos_a;
  my_rotation(object, matrix, matrix_opo);
  return (0);
}

int		my_rotation_y(t_object *object, int angle)
{
  t_matrix	*matrix;
  t_matrix	*matrix_opo;
  double	cos_a;
  double	sin_a;

  if (object == NULL || (matrix = my_identity(4)) == NULL ||
      (matrix_opo = my_identity(4)) == NULL)
    return (1);
  object->degres_y = angle;
  cos_a = cos(angle * MY_PI / 180);
  sin_a = sin(angle * MY_PI / 180);
  matrix->matrix[0][0] = cos_a;
  matrix->matrix[0][2] = sin_a;
  matrix->matrix[2][0] = -sin_a;
  matrix->matrix[2][2] = cos_a;
  cos_a = cos(-angle * MY_PI / 180);
  sin_a = sin(-angle * MY_PI / 180);
  matrix_opo->matrix[0][0] = cos_a;
  matrix_opo->matrix[0][2] = sin_a;
  matrix_opo->matrix[2][0] = -sin_a;
  matrix_opo->matrix[2][2] = cos_a;
  my_rotation(object, matrix, matrix_opo);
  return (0);
}

int		my_rotation_z(t_object *object, int angle)
{
  t_matrix	*matrix;
  t_matrix	*matrix_opo;
  double	cos_a;
  double	sin_a;

  if (object == NULL || (matrix = my_identity(4)) == NULL ||
      (matrix_opo = my_identity(4)) == NULL)
    return (1);
  object->degres_z = angle;
  cos_a = cos(angle * MY_PI / 180);
  sin_a = sin(angle * MY_PI / 180);
  matrix->matrix[0][0] = cos_a;
  matrix->matrix[0][1] = -sin_a;
  matrix->matrix[1][0] = sin_a;
  matrix->matrix[1][1] = cos_a;
  cos_a = cos(-angle * MY_PI / 180);
  sin_a = sin(-angle * MY_PI / 180);
  matrix_opo->matrix[0][0] = cos_a;
  matrix_opo->matrix[0][1] = -sin_a;
  matrix_opo->matrix[1][0] = sin_a;
  matrix_opo->matrix[1][1] = cos_a;
  my_rotation(object, matrix, matrix_opo);
  return (0);
}
