/*
** main.c for main in /home/plasko_a/rendu/MUL_2013_rtv1
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Feb 27 08:00:09 2014 Antoine Plaskowski
** Last update Fri Feb 28 10:55:44 2014 Antoine Plaskowski
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

static t_matrix	**my_init_screen(t_xvar *xvar)
{
  t_matrix	**scn;
  int		i;

  if ((scn = my_malloc(sizeof(t_matrix *) * (xvar->x * xvar->y + 1))) == NULL)
    return (NULL);
  i = 0;
  while (i < xvar->x * xvar->y)
    {
      if ((scn[i] = my_new_matrix(4, 1)) == NULL)
	return (NULL);
      scn[i]->matrix[0][0] = DISTANCE;
      scn[i]->matrix[1][0] = xvar->x / 2.0 - i % xvar->x;
      scn[i]->matrix[2][0] = xvar->y / 2.0 - i / xvar->x;
      scn[i++]->matrix[3][0] = 0;
    }
  scn[i] = NULL;
  return (scn);
}

static void	my_free_screen(t_matrix **screen)
{
  int		i;

  i = 0;
  while (screen[i] != NULL)
    my_free_matrix(screen[i++]);
  free(screen);
}

static void	my_aff_screen(t_matrix **screen)
{
  int		i;

  i = 0;
  while (*screen != NULL)
    {
      my_aff_matrix(*screen++);
      printf("\n");
      i++;
    }
  printf("%d\n", i);
}

int		main(int argc, char **argv)
{
  t_rtv1	rtv1;

  argv[argc] = NULL;
  rtv1.object = NULL;
  if ((rtv1.xvar = my_init_x()) == NULL)
    return (1);
  if ((rtv1.screen = my_init_screen(rtv1.xvar)) == NULL)
    return (1);
  if (my_parsing(&rtv1, my_search_map(argv)))
    return (1);
  my_aff_all_object(rtv1.object);
  while (rtv1.object)
    rtv1.object = my_remove_object(rtv1.object);
  my_free_screen(rtv1.screen);
  my_close_x(rtv1.xvar);
  return (0);
}
