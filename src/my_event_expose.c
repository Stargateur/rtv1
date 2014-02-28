/*
** my_event_expose.c for my_event_expose in /home/plasko_a/rendu/MUL_2013_wolf3d
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Sat Jan 11 22:37:35 2014 Antoine PLASKOWSKI
** Last update Fri Feb 28 11:24:36 2014 Antoine Plaskowski
*/

#include	<X11/Xlib.h>
#include	"my_x.h"

void		my_event_expose(t_xvar *xvar)
{
  if (xvar != NULL)
    XPutImage(xvar->dpy, xvar->win, xvar->gc, xvar->img, 0, 0, 0, 0,
	      xvar->img->width, xvar->img->height);
}
