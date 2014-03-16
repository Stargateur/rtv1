/*
** my_event_key_press.c for my_event_key_press in /home/plasko_a/rendu/MUL_2013_rtv1
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Fri Mar 14 14:19:03 2014 Antoine Plaskowski
** Last update Sun Mar 16 19:54:47 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<X11/Xlib.h>

int		my_event_key_press(XEvent *event)
{
  if (event == NULL)
    return (1);
  if (event->xkey.keycode == 9)
    return (1);
  return (0);
}
