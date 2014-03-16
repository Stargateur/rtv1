/*
** my_found_inter.c for my_found_inter in /home/plasko_a/rendu/MUL_2013_rtv1
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon Mar  3 10:42:30 2014 Antoine Plaskowski
** Last update Fri Mar 14 23:27:17 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_rtv1.h"
#include	"my_str.h"

static int	my_search_inter(t_object *object, t_matrix *screen, t_k *k, int i)
{
  double	(*fct[NBR_OBJ - 2])(t_matrix *, t_matrix *, double);
  t_matrix	*matrix;
  double	tmp;

  fct[0] = &my_sphere;
  fct[1] = &my_cylinder;
  fct[2] = &my_cone;
  fct[3] = &my_plan;
  if ((matrix = my_mul_matrix(object->trans, screen)) == NULL)
    return (1);
  matrix->matrix[0][0] -= object->eye->matrix[0][0];
  matrix->matrix[1][0] -= object->eye->matrix[1][0];
  matrix->matrix[2][0] -= object->eye->matrix[2][0];
  tmp = fct[i](object->eye, matrix, object->rayon);
  if ((k->k == -1 || tmp < k->k) && tmp > 0)
    {
      my_free_matrix(k->inter);
      if ((k->inter = my_new_matrix(4, 1)) == NULL)
	return (1);
      k->inter->matrix[0][0] = object->eye->matrix[0][0] + matrix->matrix[0][0];
      k->inter->matrix[1][0] = object->eye->matrix[1][0] + matrix->matrix[1][0];
      k->inter->matrix[2][0] = object->eye->matrix[2][0] + matrix->matrix[2][0];
      k->inter->matrix[3][0] = 1;
      k->k = tmp;
      k->object = object;
    }
  my_free_matrix(matrix);
  return (0);
}

t_k		*my_found_inter(t_object *object, t_matrix *screen)
{
  char		*object_name[NBR_OBJ - 2];
  t_k		*k;
  int		i;

  if (object == NULL || screen == NULL || (k = my_malloc(sizeof(t_k))) == NULL)
    return (NULL);
  k->object = NULL;
  k->k = -1;
  k->inter = NULL;
  object_name[0] = "sphere";
  object_name[1] = "cylinder";
  object_name[2] = "cone";
  object_name[3] = "plan";
  while (object != NULL)
    {
      i = 0;
      while (i < NBR_OBJ - 2)
	if (my_strcmp(object_name[i++], object->name) == 0)
	  my_search_inter(object, screen, k, i - 1);
      object = object->next;
    }
  return (k);
}
