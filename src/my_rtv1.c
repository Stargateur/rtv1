/*
** my_rtv1.c for my_rtv1 in /home/plasko_a/rendu/MUL_2013_rtv1
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Fri Feb 28 17:25:57 2014 Antoine Plaskowski
** Last update Mon Mar  3 10:34:01 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_rtv1.h"

t_color		*my_found_color(t_rtv1 *rtv1)
{
  
  return (NULL);
}



int		my_rtv1(t_rtv1 *rtv1)
{
  t_color	*color;
  int		i;

  if (rtv1 == NULL)
    return (1);
  i = 0;
  while (i < rtv1->xvar->x * rtv1->xvar->y)
    {
      /* if ((color = my_found_color(rtv1)) == NULL) */
      /* 	return (1); */
      /* my_put_pixel_to_img(rtv1->xvar->img, color, i++ * 4); */
      i++;
    }
}
