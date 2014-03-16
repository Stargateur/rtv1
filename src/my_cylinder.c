/*
** my_cylinder.c for my_cylinder in /home/plasko_a/rendu/104intersection
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Jan  5 18:43:21 2014 Antoine PLASKOWSKI
** Last update Mon Mar  3 21:33:42 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"my_matrix.h"
#include	"my_equation_second.h"

double		my_cylinder(t_matrix *point, t_matrix *vecteur, double radius)
{
  double	a;
  double	b;
  double	c;
  int		i;

  if (point == NULL || vecteur == NULL)
    return (-1);
  a = 0;
  b = 0;
  c = 0;
  i = 0;
  while (i < 2)
    {
      a += vecteur->matrix[i][0] * vecteur->matrix[i][0];
      b += 2 * point->matrix[i][0] * vecteur->matrix[i][0];
      c += point->matrix[i][0] * point->matrix[i][0];
      i++;
    }
  c -= radius * radius;
  return (my_eq_se(a, b, c));
}
