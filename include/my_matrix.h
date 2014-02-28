/*
** my_struct_matrix.h for my_struct_matrix in /home/plasko_a/rendu/102chiffrement
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Mon Nov 25 15:47:10 2013 Antoine Plaskowski
** Last update Thu Feb 27 18:31:22 2014 Antoine Plaskowski
*/

#ifndef		MY_STRUCT_MATRIX_H_
# define	MY_STRUCT_MATRIX_H_

typedef struct	s_matrix t_matrix;
struct		s_matrix
{
  double	**matrix;
  int		m;
  int		n;
};

t_matrix	*my_new_matrix(const int m, const int n);
t_matrix	*my_mul_matrix(const t_matrix *a, const t_matrix *b);
void		my_aff_matrix(const t_matrix *a);
void		my_free_matrix(t_matrix *matrix);

#endif		/* !MY_STRUCT_MATRIX_H_ */
