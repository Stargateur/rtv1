/*
** my_tool_matrix.c for my_tool_matrix in /home/plasko_a/rendu/MUL_2013_rtv1
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Mon Mar  3 13:38:04 2014 Antoine Plaskowski
** Last update Mon Mar  3 13:48:00 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"my_matrix.h"
#include	"my_str.h"

static double	my_mul_anx(const t_matrix *a, const t_matrix *b,
			   const int i, const int j)
{
  int		k;
  double	result;

  if (a == NULL || b == NULL)
    return (0);
  result = 0;
  k = 0;
  while (k < a->n)
    {
      result += a->matrix[i][k] * b->matrix[k][j];
      k++;
    }
  return (result);
}

t_matrix	*my_mul_matrix(const t_matrix *a, const t_matrix *b)
{
  t_matrix	*matrix;
  int		i;
  int		j;

  if (a == NULL || b == NULL)
    return (NULL);
  if (a->n != b->m)
    {
      my_putstr("Impossible multiple matrix\n", 2);
      return (NULL);
    }
  if ((matrix = my_new_matrix(a->m, b->n)) == NULL)
    return (NULL);
  i = 0;
  while (i < a->m)
    {
      j = 0;
      while (j < b->n)
	{
	  matrix->matrix[i][j] = my_mul_anx(a, b, i, j);
	  j++;
	}
      i++;
    }
  return (matrix);
}

void		my_aff_matrix(const t_matrix *matrix)
{
  int		i;

  if (matrix != NULL || matrix->matrix != NULL)
    {
      i = 0;
      printf("(");
      while (i < matrix->m)
	{
	  printf("%.3f", matrix->matrix[i][0]);
	  i++;
	  if (i != matrix->m)
	    printf(", ");
	}
      printf(")");
    }
}

void		my_free_matrix(t_matrix *matrix)
{
  int		i;

  i = 0;
  while (i < matrix->m)
    {
      free(matrix->matrix[i]);
      i++;
    }
  free(matrix->matrix);
  free(matrix);
}
