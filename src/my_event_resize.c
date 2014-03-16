/*
** my_event_resize.c for my_event_resize in /home/plasko_a/rendu/MUL_2013_wolf3d/src
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Fri Jan  3 09:42:08 2014 Antoine PLASKOWSKI
** Last update Fri Mar 14 15:30:15 2014 Antoine Plaskowski
*/

#include	<X11/Xlib.h>
#include	<X11/Xutil.h>
#include	"my_x.h"

int		my_event_resize(t_xvar *xvar, XEvent *event)
{
  xvar->x = event->xresizerequest.width;
  xvar->y = event->xresizerequest.height;
  XDestroyWindow(xvar->dpy, xvar->win);
  XDestroyImage(xvar->img);
  my_create_window(xvar);
  if (my_create_image(xvar))
    return (1);;
  return (0);
}
