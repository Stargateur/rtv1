/*
** my_found_color.c for my_found_color in /home/plasko_a/rendu/MUL_2013_rtv1
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Fri Mar 14 17:28:56 2014 Antoine Plaskowski
** Last update Sun Mar 16 20:03:10 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_rtv1.h"
#include	"my_str.h"

static int	my_fnd_itr_lgt(t_matrix *lgt, t_matrix *vctr, t_object *obj)
{
  double	(*fct[NBR_OBJ - 2])(t_matrix *, t_matrix *, double);
  char          *object_name[NBR_OBJ - 2];
  int           i;
  double	tmp;

  if (lgt == NULL || vctr == NULL)
    return (1);
  object_name[0] = "sphere";
  object_name[1] = "cylinder";
  object_name[2] = "cone";
  object_name[3] = "plan";
  fct[0] = &my_sphere;
  fct[1] = &my_cylinder;
  fct[2] = &my_cone;
  fct[3] = &my_plan;
  i = 0;
  while (i < NBR_OBJ - 2)
    if (my_strcmp(object_name[i++], obj->name) == 0)
      {
	tmp = fct[i - 1](lgt, vctr, obj->rayon);
	if (tmp > 0 && tmp < 1)
	  return (1);
      }
  return (0);
}

static t_matrix	*my_trans_light(t_object *object, t_object *light)
{
  t_matrix	*trans;
  t_matrix	*tmp2;

  if ((tmp2 = my_mul_matrix(object->ro_opo, light->ro)) == NULL)
    return (NULL);
  if ((trans = my_mul_matrix(tmp2, object->po_opo)) == NULL)
    return (NULL);
  my_free_matrix(tmp2);
  return (trans);
}

static t_matrix	*my_help_inter_light(t_object *light, t_matrix *trans)
{
  t_matrix	*matrix;
  t_matrix	*tmp2;

  if ((tmp2 = my_new_matrix(4, 1)) == NULL)
    return (NULL);
  tmp2->matrix[0][0] = light->po->matrix[0][3];
  tmp2->matrix[1][0] = light->po->matrix[1][3];
  tmp2->matrix[2][0] = light->po->matrix[2][3];
  tmp2->matrix[3][0] = 1;
  if ((matrix = my_mul_matrix(trans, tmp2)) == NULL)
    return (NULL);
  my_free_matrix(tmp2);
  return (matrix);
}

static int	my_inter_light(t_object *light, t_object *object,
			       t_k *k, int bool)
{
  t_matrix	*matrix;
  t_matrix	*inter;
  t_matrix	*trans;

  while (object != NULL)
    {
      if (object != k->object)
	{
	  if ((trans = my_trans_light(object, light)) == NULL ||
	      (matrix = my_help_inter_light(light, trans)) == NULL ||
	      (inter = my_mul_matrix(trans, k->inter)) == NULL)
	    return (0);
	  my_free_matrix(trans);
	  inter->matrix[0][0] -= matrix->matrix[0][0];
	  inter->matrix[1][0] -= matrix->matrix[1][0];
	  inter->matrix[2][0] -= matrix->matrix[2][0];
	  bool = my_fnd_itr_lgt(matrix, inter, object);
	  my_free_matrix(matrix);
	  my_free_matrix(inter);
	  if (bool)
	    return (1);
	}
      object = object->next;
    }
  return (0);
}

t_color		*my_found_color(t_object *light, t_object *object, t_k *k)
{
  t_color	*color;
  int		len;

  if (k == NULL || (color = my_malloc(sizeof(t_color))) == NULL)
    return (NULL);
  len = my_len_object(light);
  color->color = 0;
  while (light != NULL)
    {
      if (my_inter_light(light, object, k, 0) == 0)
	{
	  color->comp.r += k->object->color.comp.r / len;
	  color->comp.v += k->object->color.comp.v / len;
	  color->comp.b += k->object->color.comp.b / len;
	  color->comp.a += k->object->color.comp.a / len;
	}
      light = light->next;
    }
  return (color);
}
