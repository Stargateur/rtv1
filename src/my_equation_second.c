/*
** my_equation_second.c for my_equation_second in /home/plasko_a/rendu/104intersection
** 
** Made by Antoine PLASKOWSKI
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Jan  5 18:43:49 2014 Antoine PLASKOWSKI
** Last update Fri Feb 28 17:14:41 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<math.h>
#include	"my_matrix.h"

double		my_solve_second(double a, double b, double c)
{
  double	delta;
  double	x1;
  double	x2;

  x1 = -1;
  x2 = -1;
  if (a != 0)
    {
      if ((delta = b * b - 4 * a * c) >= 0)
	{
	  x1 = (-b - sqrt(delta)) / (2 * a);
	  x2 = (-b + sqrt(delta)) / (2 * a);
	}
    }
  else if (b != 0)
    x1 = -c / b;
  else
    x1 = c;
  if (abs(x1) < abs(x2))
    return (x1);
  return (x2);
}
