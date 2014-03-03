/*
** my_object.c for my_object in /home/plasko_a/rendu/MUL_2013_rtv1
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Feb 27 08:51:22 2014 Antoine Plaskowski
** Last update Mon Mar  3 13:59:42 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_rtv1.h"
#include	"my_str.h"
#include	"my_matrix.h"

static int	my_init_object(t_object *object)
{
  object->prev = NULL;
  object->name = NULL;
  if ((object->position = my_identity(4)) == NULL)
    return (1);
  if ((object->rotation_x = my_identity(4)) == NULL)
    return (1);
  if ((object->rotation_y = my_identity(4)) == NULL)
    return (1);
  if ((object->rotation_z = my_identity(4)) == NULL)
    return (1);
  object->rotation_x_degres = 0;
  object->rotation_y_degres = 0;
  object->rotation_z_degres = 0;
  object->rayon = 0;
  object->color.color = 0xFFFFFF;
  object->next = NULL;
  return (0);
}

static int	my_name_object(t_object *object, char *str)
{
  char		*object_name[NBR_OBJ];
  int		i;

  object_name[0] = "sphere";
  object_name[1] = "eye";
  object_name[2] = "cylinder";
  object_name[3] = "cone";
  object_name[4] = "plan";
  object_name[5] = "light";
  i = 0;
  while (i < NBR_OBJ)
    if (my_strcmp(object_name[i++], str) == 0)
      {
	if ((object->name = my_strdup(str)) == NULL)
	  return (1);
	return (0);
      }
  my_putstr(str, 2);
  my_putstr(" : is not a valide object\n", 2);
  return (1);
}

static int	my_set_var(t_object *object, char *str, int i)
{
  if (i == 0)
    object->position->matrix[0][4] = my_getnbr(str);
  else if (i == 1)
    object->position->matrix[1][4] = my_getnbr(str);
  else if (i == 2)
    object->position->matrix[2][4] = my_getnbr(str);
  else if (i == 3)
    my_rotation_x(object, my_getnbr(str));
  else if (i == 4)
    my_rotation_y(object, my_getnbr(str));
  else if (i == 5)
    my_rotation_z(object, my_getnbr(str));
  else if (i == 6)
    object->rayon = my_getnbr(str);
  else if (i == 7)
    object->color.color = my_getnbr_base(str, "012345679ABCDEF");
  else
    return (-1);
  return (i);
}

static int	my_var_object(t_object *object, char *str)
{
  char		*var[NBR_VAR];
  int		i;

  var[0] = "position_x=";
  var[1] = "position_y=";
  var[2] = "position_z=";
  var[3] = "rotation_x=";
  var[4] = "rotation_y=";
  var[5] = "rotation_z=";
  var[6] = "rayon=";
  var[7] = "color=";
  i = 0;
  while (i < NBR_VAR)
    {
      if (my_strncmp(var[i], str, my_strlen(var[i])) == 0)
	return (my_set_var(object, str + my_strlen(var[i]), i));
      i++;
    }
  my_putstr(str, 2);
  my_putstr(" : is not a valide variable\n", 2);
  return (-1);
}

t_object	*my_new_object(t_object *object, char **wordtab)
{
  t_object	*new_object;
  int		*var[NBR_VAR];
  int		i;

  if (wordtab == NULL)
    return (NULL);
  if ((new_object = my_malloc(sizeof(t_object))) == NULL)
    return (NULL);
  i = 0;
  while (i < NBR_VAR)
    var[i++] = 0;
  if (my_init_object(new_object))
    return (NULL);
  if (my_name_object(new_object, *wordtab++))
    return (NULL);
  while (*wordtab)
    if ((i = my_var_object(new_object, *wordtab++)) == -1)
      return (NULL);
    else if (var[i])
      my_putstr("error a variable is set more than 1 time\n", 2);
    else
      var[i]++;
  return (my_insert_object(object, new_object));
}
