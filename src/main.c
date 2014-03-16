/*
** main.c for main in /home/plasko_a/rendu/MUL_2013_rtv1
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Feb 27 08:00:09 2014 Antoine Plaskowski
** Last update Sun Mar 16 12:34:30 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_rtv1.h"
#include	"my_str.h"

static char	*my_search_map(char **argv)
{
  while (*argv)
    if (my_strcmp(*argv++, "-s") == 0)
      if (*argv)
	return (*argv);
  my_putstr("no scene file\n", 2);
  return (NULL);
}

int		main(int argc, char **argv)
{
  t_rtv1	rtv1;

  argv[argc] = NULL;
  rtv1.object = NULL;
  if ((rtv1.xvar = my_init_x()) == NULL)
    return (1);
  if (my_load_scene(&rtv1, my_search_map(argv)))
    return (1);
  my_aff_object(rtv1.eye);
  my_aff_all_object(rtv1.light);
  my_aff_all_object(rtv1.object);
  my_rtv1(&rtv1);
  while (rtv1.object != NULL)
    rtv1.object = my_remove_object(rtv1.object);
  rtv1.eye = my_remove_object(rtv1.eye);
  my_close_x(rtv1.xvar);
  return (0);
}
