/*
** my_sphere.c for my_sphere in /home/plasko_a/rendu/104intersection
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Jan  5 18:43:59 2014 Antoine PLASKOWSKI
** Last update Mon Jan  6 15:57:41 2014 Antoine PLASKOWSKI
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"my_struct_matrix.h"
#include	"my_equation_second.h"
#include	"my_str.h"

static double	my_c(t_matrix *point, t_matrix *ogn, double radius)
{
  double	c;
  int		i;

  i = 0;
  c = 0;
  while (i < 3)
    {
      c += point->matrix[i][0] * point->matrix[i][0];
      c += ogn->matrix[i][0] * ogn->matrix[i][0];
      c -= 2 * ogn->matrix[i][0] * point->matrix[i][0];
      i++;
    }
  c -= radius * radius;
  return (c);
}

static double	my_b(t_matrix *point, t_matrix *vecteur, t_matrix *ogn)
{
  double	b;
  int		i;

  i = 0;
  b = 0;
  while (i < 3)
    {
      b += 2 * point->matrix[i][0] * vecteur->matrix[i][0];
      b -= 2 * ogn->matrix[i][0] * vecteur->matrix[i][0];
      i++;
    }
  return (b);
}

static double	my_a(t_matrix *vecteur)
{
  double	a;
  int		i;

  i = 0;
  a = 0;
  while (i < 3)
    {
      a += vecteur->matrix[i][0] * vecteur->matrix[i][0];
      i++;
    }
  return (a);
}

int		my_sphere(t_matrix *point, t_matrix *vecteur,
			  t_matrix *ogn, double radius)
{
  double	a;
  double	b;
  double	c;
  t_matrix	**matrix;

  if ((matrix = my_malloc(sizeof(t_matrix *) * 2)) == NULL)
    return (1);
  matrix[0] = point;
  matrix[1] = vecteur;
  a = my_a(vecteur);
  b = my_b(point, vecteur, ogn);
  c = my_c(point, ogn, radius);
  printf("sphere of radius %.3f\n", radius);
  printf("line passing by the point ");
  my_aff_matrix(point);
  printf(", of direction vector ");
  my_aff_matrix(vecteur);
  printf("\n");
  if (a || b || c)
    return (my_eq_se(a, b, c, matrix));
  printf("The point is on the sphere\n");
  return (0);
}
