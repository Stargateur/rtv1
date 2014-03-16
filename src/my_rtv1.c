/*
** my_rtv1.c for my_rtv1 in /home/plasko_a/rendu/MUL_2013_rtv1
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Fri Feb 28 17:25:57 2014 Antoine Plaskowski
** Last update Sun Mar 16 20:05:30 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<math.h>
#include	"my_rtv1.h"

static int	my_help_set_image(t_xvar *xvar, t_matrix *scn, int x, int y)
{
  scn->matrix[0][0] = xvar->y / tan(DISTANCE * MY_PI / 180);
  scn->matrix[1][0] = xvar->x / 2.0 - x;
  scn->matrix[2][0] = xvar->y / 2.0 - y;
  scn->matrix[3][0] = 1;
  return (0);
}

static void	my_free_k(t_k *k)
{
  my_free_matrix(k->inter);
  my_free_matrix(k->inter_nor);
  free(k);
}

static int	my_set_image(t_xvar *xvar, t_object *object, t_object *light)
{
  t_matrix	*scn;
  t_k		*k;
  int		x;
  int		y;

  if ((scn = my_new_matrix(4, 1)) == NULL || light == NULL)
    return (1);
  y = 0;
  while (y < xvar->y)
    {
      x = 0;
      while (x < xvar->x)
	{
	  my_help_set_image(xvar, scn, x, y);
	  if ((k = my_found_inter(object, scn)) == NULL)
	    return (1);
	  if (k->k > 0)
	    my_put_p_i(xvar->img, &k->object->color, (y * xvar->x + x) * 4);
	  my_free_k(k);
	  x++;
	}
      y++;
    }
  my_free_matrix(scn);
  return (0);
}

static int	my_event_rtv1(t_rtv1 *rtv1)
{
  XEvent	event;

  while (42)
    {
      while (XPending(rtv1->xvar->dpy))
        {
          XNextEvent(rtv1->xvar->dpy, &event);
	  if (event.type == KeyPress)
	    {
	      if (my_event_key_press(&event))
		return (0);
	    }
	  else if (event.type == ResizeRequest)
	    {
	      if (my_event_resize(rtv1->xvar, &event))
		return (1);
	      my_set_image(rtv1->xvar, rtv1->object, rtv1->light);
	    }
	  else if (event.type == Expose)
	    my_event_expose(rtv1->xvar);
	}
    }
  return (1);
}

int		my_rtv1(t_rtv1 *rtv1)
{
  my_set_image(rtv1->xvar, rtv1->object, rtv1->light);
  return (my_event_rtv1(rtv1));
}
