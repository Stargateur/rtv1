/*
** my_plan.c for my_plan in /home/plasko_a/rendu/MUL_2013_rtv1
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon Mar  3 19:21:38 2014 Antoine Plaskowski
** Last update Sun Mar 16 18:08:22 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"my_matrix.h"
#include	"my_equation_second.h"

double		my_plan(t_matrix *point, t_matrix *vecteur, double radius)
{
  double	a;
  double	b;
  double	c;

  if (point == NULL || vecteur == NULL)
    return (-1);
  (void) radius;
  a = 0;
  b = vecteur->matrix[2][0];
  c = point->matrix[2][0];
  return (my_eq_se(a, b, c));
}
