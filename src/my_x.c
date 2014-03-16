/*
** my_x.c for my_x in /home/plasko_a/rendu/MUL_2013_wolf3d/src
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Fri Jan  3 09:41:53 2014 Antoine PLASKOWSKI
** Last update Sun Mar 16 20:09:59 2014 Antoine Plaskowski
*/

#include			<X11/Xlib.h>
#include			<X11/Xutil.h>
#include			<stdlib.h>
#include			"my_x.h"
#include			"my_str.h"

static XSetWindowAttributes	*my_set_at(XSetWindowAttributes *at)
{
  at->background_pixmap = None;
  at->background_pixel = 0;
  at->border_pixmap = None;
  at->border_pixel = 0;
  at->bit_gravity = 0;
  at->win_gravity = 0;
  at->backing_store = 0;
  at->backing_planes = 0;
  at->backing_pixel = 0;
  at->save_under = 0;
  at->event_mask = PointerMotionMask | KeyPressMask | KeyReleaseMask
    | ExposureMask | ButtonPressMask | ButtonReleaseMask | ResizeRedirectMask
    | PointerMotionMask | StructureNotifyMask;
  at->do_not_propagate_mask = 0;
  at->override_redirect = 0;
  at->colormap = None;
  at->cursor = None;
  return (at);
}

void				my_create_window(t_xvar *xvar)
{
  XSetWindowAttributes		at;

  xvar->win = XCreateWindow(xvar->dpy, DefaultRootWindow(xvar->dpy),
			    xvar->x / 2 , xvar->y / 2, xvar->x, xvar->y, 0, 0,
			    0, CopyFromParent, CWEventMask, my_set_at(&at));
  XStoreName(xvar->dpy, xvar->win, "RayTracer");
  XMapWindow(xvar->dpy, xvar->win);
}

int				my_create_image(t_xvar *xvar)
{
  char				*img;

  if ((img = my_malloc(sizeof(char) * 4 * xvar->x * xvar->y)) == NULL)
    return (1);
  if ((xvar->img = XCreateImage(xvar->dpy, DefaultVisual(xvar->dpy, xvar->scn),
				DefaultDepth(xvar->dpy, xvar->scn), ZPixmap, 0,
				img, xvar->x, xvar->y, 32, 0)) == NULL)
    {
      my_putstr("Error : create image\n", 2);
      return (1);
    }
  return (0);
}

t_xvar				*my_init_x(void)
{
  t_xvar			*xvar;

  if ((xvar = my_malloc(sizeof(t_xvar))) == NULL)
    return (NULL);
  if ((xvar->dpy = XOpenDisplay(NULL)) == NULL)
    {
      my_putstr("NO DISPLAY DEFAULT\n", 2);
      return (NULL);
    }
  XAutoRepeatOn(xvar->dpy);
  xvar->scn = DefaultScreen(xvar->dpy);
  xvar->gc = DefaultGC(xvar->dpy, xvar->scn);
  xvar->x = DisplayWidth(xvar->dpy, xvar->scn) / 2;
  xvar->y = DisplayHeight(xvar->dpy, xvar->scn) / 2;
  my_create_window(xvar);
  if (my_create_image(xvar))
    return (NULL);
  return (xvar);
}

void				my_close_x(t_xvar *xvar)
{
  if (xvar != NULL)
    {
      if (xvar->img != NULL)
	XDestroyImage(xvar->img);
      XCloseDisplay(xvar->dpy);
      free(xvar);
    }
}
