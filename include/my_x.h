/*
** my_x.h for my_x in /home/plasko_a/rendu/MUL_2013_wolf3d
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Fri Jan  3 10:09:09 2014 Antoine PLASKOWSKI
** Last update Fri Feb 28 11:10:53 2014 Antoine Plaskowski
*/

#ifndef		MY_X_H_
# define	MY_X_H_

# include	<X11/Xlib.h>

typedef struct	s_xvar
{
  Display	*dpy;
  XImage	*img;
  GC		gc;
  Window	win;
  int		x;
  int		y;
  int		scn;
}		t_xvar;

/*
**		my_x.c
*/

t_xvar		*my_init_x(void);
void		my_close_x(t_xvar *xvar);

#endif		/* !MY_X_H_ */
