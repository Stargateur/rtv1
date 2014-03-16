/*
** my_struct_matrix.h for my_struct_matrix in /home/plasko_a/rendu/102chiffrement
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Mon Nov 25 15:47:10 2013 Antoine Plaskowski
** Last update Mon Mar  3 16:50:53 2014 Antoine Plaskowski
*/

#ifndef		MY_STRUCT_MATRIX_H_
# define	MY_STRUCT_MATRIX_H_

# define	MY_PI			3.14159265358979323846

typedef struct	s_matrix t_matrix;
struct		s_matrix
{
  double	**matrix;
  int		m;
  int		n;
};

/*
**		my_matrix.c
*/

t_matrix	*my_new_matrix(const int m, const int n);
t_matrix	*my_cpy_matrix(t_matrix *matrix);
t_matrix	*my_identity(const int m);

/*
**		my_tool_matrix.c
*/

t_matrix	*my_mul_matrix(const t_matrix *a, const t_matrix *b);
void		my_aff_matrix(const t_matrix *a);
void		my_free_matrix(t_matrix *matrix);

/*
**		my_tool2_matrix.c
*/

t_matrix	*my_mul_opo_matrix(const t_matrix *a, const t_matrix *b);

#endif		/* !MY_STRUCT_MATRIX_H_ */
