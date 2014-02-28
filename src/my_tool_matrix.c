/*
** my_tool_matrix.c for my_tool_matrix in /home/plasko_a/rendu/MUL_2013_rtv1
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Fri Feb 28 10:35:21 2014 Antoine Plaskowski
** Last update Fri Feb 28 10:39:50 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_matrix.h"

t_matrix	*my_cpy_matrix(t_matrix *matrix)
{
  t_matrix	*cpy;
  int		i;
  int		j;

  if (matrix == NULL)
    return (NULL);
  if ((cpy = my_new_matrix(matrix->m, matrix->m)) == NULL)
    return (NULL);
  i = 0;
  while (i < matrix->m)
    {
      j = 0;
      while (j < matrix->n)
	{
	  cpy->matrix[i][j] = matrix->matrix[i][j];
	  j++;
	}
      i++;
    }
  return (cpy);
}
