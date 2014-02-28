/*
** my_str.h for my_str in /home/plasko_a/rendu/PSU_2013_minishell1/header
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sat Dec 14 23:00:22 2013 Antoine Plaskowski
** Last update Thu Feb 27 18:22:02 2014 Antoine Plaskowski
*/

#ifndef		MY_STR_H_
# define	MY_STR_H_

int		my_putchar(const char c, const int fd);
int		my_putstr(const char *str, const int fd);
int		my_strlen(const char *str);
int		my_strcpy(char *dest, const char *src);
int		my_strncpy(char *dest, const char *src, int n);
int		my_putnbr(int nb, const int fd);
int		my_putnbr_base(int nb, const char *base, const int fd);
int		my_getnbr(const char *str);
int		my_getnbr_base(const char *str, const char *base);
char		*my_strdup(const char *str);
char		*my_strndup(const char *str, int n);
char		*my_strcat(const char *str1, const char *str2);
int		my_strcmp(const char *s1, const char *s2);
int		my_strncmp(const char *s1, const char *s2, const int n);
int		my_char_in_str(const char c, const char *str);

void		*my_malloc(unsigned long size_octect);

/*
** my_str_to_wordtab.c
*/

char		**my_str_to_wordtab(const char *str);

#endif		/* MY_STR_ */
