/*
** my_found_color.c for my_found_color in /home/plasko_a/rendu/MUL_2013_rtv1
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Fri Mar 14 17:28:56 2014 Antoine Plaskowski
** Last update Sun Mar 16 12:15:41 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_rtv1.h"
#include	"my_str.h"

static int	my_found_inter_light(t_matrix *light, t_matrix *vecteur, t_object *object)
{
  double	(*fct[NBR_OBJ - 2])(t_matrix *, t_matrix *, double);
  char          *object_name[NBR_OBJ - 2];
  int           i;
  double	tmp;

  if (light == NULL || vecteur == NULL)
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
    if (my_strcmp(object_name[i++], object->name) == 0)
      {
	tmp = fct[i - 1](light, vecteur, object->rayon);
	if (tmp > 0 && tmp < 1)
	  return (1);
      }
  return (0);
}

static int	my_inter_light(t_object *light, t_object *object, t_k *k, t_matrix *vecteur)
{
  t_matrix	*matrix;
  t_matrix	*inter;
  t_matrix	*tmp;
  t_matrix	*tmp2;

  while (object != NULL)
    {
      if ((tmp = my_mul_matrix(object->ro, object->po)) == NULL)
	return (0);
      if ((tmp2 = my_mul_matrix(tmp, light->po)) == NULL)
	return (0);
      my_free_matrix(tmp);
      if ((tmp = my_new_matrix(4, 1)) == NULL)
	return (0);
      tmp->matrix[3][0] = 1;
      if ((matrix = my_mul_matrix(tmp2, tmp)) == NULL)
	return (0);
      my_free_matrix(tmp);
      my_free_matrix(tmp2);
      if ((tmp = my_mul_matrix(object->po, object->ro)) == NULL)
	return (0);
      if ((inter = my_mul_matrix(tmp, k->inter)) == NULL)
	return (0);
      my_free_matrix(tmp);
      vecteur->matrix[0][0] = matrix->matrix[0][0] - inter->matrix[0][0];
      vecteur->matrix[1][0] = matrix->matrix[1][0] - inter->matrix[1][0];
      vecteur->matrix[2][0] = matrix->matrix[2][0] - inter->matrix[2][0];
      if (my_found_inter_light(matrix, vecteur, object))
	return (1);
      my_free_matrix(matrix);
      my_free_matrix(inter);
      object = object->next;
    }
  return (0);
}

t_color		*my_found_color(t_object *light, t_object *object, t_k *k)
{
  t_color	*color;
  t_matrix	*vecteur;
  int		len;

  if (k == NULL || (color = my_malloc(sizeof(t_color))) == NULL)
    return (NULL);
  if ((vecteur = my_new_matrix(3, 1)) == NULL)
    return (NULL);
  len = my_len_object(light);
  color->color = 0;
  while (light != NULL)
    {
      if (my_inter_light(light, object, k, vecteur) == 0)
	{
	  color->comp.r += k->object->color.comp.r / len;
	  color->comp.v += k->object->color.comp.v / len;
	  color->comp.b += k->object->color.comp.b / len;
	  color->comp.a += k->object->color.comp.a / len;
	}
      light = light->next;
    }
  my_free_matrix(vecteur);
  return (color);
}
