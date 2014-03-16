/*
** my_matrix.c for my_matrix in /home/plasko_a/rendu/102chiffrement
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Mon Nov 25 15:48:04 2013 Antoine Plaskowski
** Last update Sun Mar 16 18:04:44 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"my_matrix.h"
#include	"my_str.h"

t_matrix	*my_new_matrix(const int m, const int n)
{
  t_matrix	*matrix;
  int		i;
  int		j;

  if ((matrix = my_malloc(sizeof(t_matrix))) == NULL)
    return (NULL);
  if ((matrix->matrix = my_malloc(sizeof(double *) * m)) == NULL)
    return (NULL);
  i = 0;
  while (i < m)
    {
      if ((matrix->matrix[i] = my_malloc(sizeof(double) * n)) == NULL)
	return (NULL);
      j = 0;
      while (j < n)
	matrix->matrix[i][j++] = 0;
      i++;
    }
  matrix->m = m;
  matrix->n = n;
  return (matrix);
}

t_matrix	*my_cpy_matrix(t_matrix *matrix)
{
  t_matrix	*cpy;
  int		i;
  int		j;

  if (matrix == NULL || (cpy = my_malloc(sizeof(t_matrix))) == NULL)
    return (NULL);
  if ((cpy->matrix = my_malloc(sizeof(double *) * matrix->m)) == NULL)
    return (NULL);
  i = 0;
  while (i < matrix->m)
    {
      if ((cpy->matrix[i] = my_malloc(sizeof(double) * matrix->n)) == NULL)
	return (NULL);
      j = 0;
      while (j < matrix->n)
	{
	  cpy->matrix[i][j] = matrix->matrix[i][j];
	  j++;
	}
      i++;
    }
  cpy->m = matrix->m;
  cpy->n = matrix->n;
  return (cpy);
}

t_matrix	*my_identity(const int m)
{
  t_matrix	*matrix;
  int		i;
  int		j;

  if ((matrix = my_malloc(sizeof(t_matrix))) == NULL)
    return (NULL);
  if ((matrix->matrix = my_malloc(sizeof(double *) * m)) == NULL)
    return (NULL);
  i = 0;
  while (i < m)
    {
      if ((matrix->matrix[i] = my_malloc(sizeof(double) * m)) == NULL)
	return (NULL);
      j = 0;
      while (j < m)
	if (i != j)
	  matrix->matrix[i][j++] = 0;
	else
	  matrix->matrix[i][j++] = 1;
      i++;
    }
  matrix->m = m;
  matrix->n = m;
  return (matrix);
}
