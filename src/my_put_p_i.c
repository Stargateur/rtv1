/*
** my_put_p_i.c for my_put_p_i in /home/plasko_a/rendu/MUL_2013_rtv1
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Mar 16 20:04:26 2014 Antoine Plaskowski
** Last update Sun Mar 16 20:04:32 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<X11/Xlib.h>
#include	"my_rtv1.h"

int		my_put_p_i(XImage *img, t_color *color, int x)
{
  if (img == NULL || color == NULL)
    return (1);
  if (x < 0 || x > img->height * img->width * 4 - 4)
    return (1);
  img->data[x++] = color->comp.r;
  img->data[x++] = color->comp.v;
  img->data[x++] = color->comp.b;
  img->data[x] = color->comp.a;
  return (0);
}
