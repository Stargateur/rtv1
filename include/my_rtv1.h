/*
** my_rtv1.h for my_rtv1 in /home/plasko_a/rendu/MUL_2013_rtv1
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Feb 27 08:20:47 2014 Antoine Plaskowski
** Last update Mon Mar  3 12:12:18 2014 Antoine Plaskowski
*/

#ifndef		MY_RTV1_H_
# define	MY_RTV1_H_

# define	NBR_OBJ		6
# define	NBR_VAR		8
# define	DISTANCE	100

# include	"my_x.h"
# include	"my_matrix.h"

typedef union	u_color t_color;
union		u_color
{
  int		color;
  struct
  {
    char	r;
    char	b;
    char	v;
    char	a;
  }		comp;
};

typedef struct	s_object t_object;
struct		s_object
{
  t_object	*prev;
  char		*name;
  t_matrix	*position;
  t_matrix	*rotation_x;
  t_matrix	*rotation_y;
  t_matrix	*rotation_z;
  int		rotation_x_degres;
  int		rotation_y_degres;
  int		rotation_z_degres;
  int		rayon;
  t_color	color;
  t_object	*next;
};

typedef struct	s_rtv1 t_rtv1;
struct		s_rtv1
{
  t_xvar	*xvar;
  t_object	*object;
  t_object	*eye;
  t_matrix	**screen;
};

/*
**		my_rtv1.c
*/

int		my_rtv1(t_rtv1 * rtv1);

/*
**		my_object.c
*/

t_object	*my_new_object(t_object *object, char **wordtab);
t_object	*my_put_object(t_object *object, t_object *new_object);

/*
**		my_tool_object.c
*/

int		my_aff_all_object(t_object *object);
int		my_aff_object(t_object *object);
t_object	*my_remove_object(t_object *object);
t_object	*my_insert_object(t_object *object, t_object *new_object);
t_object	*my_cpy_object(t_object * object);

/*
**		my_load_scene.c
*/

int		my_load_scene(t_rtv1 *rtv1, char *paht);

/*
**		my_put_pixel_to_img.c
*/

int		my_put_pixel_to_img(XImage *img, t_color *color, int x);

/*
**		my_rotation.c
*/

int             my_rotation_x(t_object *object, int angle);
int             my_rotation_y(t_object *object, int angle);
int             my_rotation_z(t_object *object, int angle);

#endif		/* !MY_RTV1_H_ */
