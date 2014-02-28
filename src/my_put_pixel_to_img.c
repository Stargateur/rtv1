/*
** my_put_pixel_to_img.c for my_put_pixel_to_img in /home/plasko_a/Documents/PROJET/tp2
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Tue Nov 12 17:39:21 2013 Antoine Plaskowski
** Last update Fri Feb 28 11:06:14 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<X11/Xlib.h>
#include	"my_rtv1.h"

int		my_put_pixel_to_img(XImage *img, t_color *color, int x)
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
