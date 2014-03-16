/*
** my_cone.c for my_cone in /home/plasko_a/rendu/104intersection
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Jan  5 18:44:07 2014 Antoine PLASKOWSKI
** Last update Tue Mar  4 10:48:27 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<math.h>
#include	"my_matrix.h"
#include	"my_equation_second.h"
#include	"my_rtv1.h"

double		my_cone(t_matrix *point, t_matrix *vecteur, double angle)
{
  double	tg;
  double	a;
  double	b;
  double	c;
  int		i;

  if (point == NULL || vecteur == NULL)
    return (1);
  tg = angle;
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
  a -= (vecteur->matrix[2][0] * vecteur->matrix[2][0]) / (tg * tg);
  b -= (2 * point->matrix[i][0] * vecteur->matrix[i][0]) / (tg * tg);
  c -= (point->matrix[i][0] * point->matrix[i][0]) / (tg * tg);
  return (my_eq_se(a, b, c));
}
