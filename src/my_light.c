/*
** my_light.c for my_light in /home/plasko_a/rendu/MUL_2013_rtv1
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Fri Mar 14 18:33:04 2014 Antoine Plaskowski
** Last update Fri Mar 14 22:43:13 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_rtv1.h"
#include	"my_str.h"

int		my_light(t_rtv1 *rtv1)
{
  if (rtv1 == NULL)
    return (1);
  rtv1->light = NULL;
  while (rtv1->object->next != NULL)
    {
      if ((my_strcmp(rtv1->object->name, "light")) == 0)
	{
	  if ((rtv1->light = my_insert_object(rtv1->light, my_cpy_object(rtv1->object))) == NULL)
	    return (1);
	  if ((rtv1->object = my_remove_object(rtv1->object)) == NULL)
	    return (0);
	}
      else
	rtv1->object = rtv1->object->next;
    }
  if ((my_strcmp(rtv1->object->name, "light")) == 0)
    {
      if ((rtv1->light = my_insert_object(rtv1->light, my_cpy_object(rtv1->object))) == NULL)
	return (1);
      rtv1->object = my_remove_object(rtv1->object);
    }
  if (rtv1->light != NULL)
    while (rtv1->light->prev != NULL)
      rtv1->light = rtv1->light->prev;    
  if (rtv1->object != NULL)
    while (rtv1->object->prev != NULL)
      rtv1->object = rtv1->object->prev;
  return (0);
}
