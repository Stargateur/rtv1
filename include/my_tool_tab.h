/*
** my_tool_tab.h for my_tool_tab in /home/plasko_a/rendu/PSU_2013_minishell1/header
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Dec 15 23:34:52 2013 Antoine Plaskowski
** Last update Thu Feb 27 09:06:05 2014 Antoine Plaskowski
*/

#ifndef		MY_TOOL_TAB_H_
# define	MY_TOOL_TAB_H_

void		my_free_tab(char **tab);
char		**my_cpy_tab(char **tab);
int		my_aff_tab(char **tab, const int fd);
int		my_len_tab(char **tab);

#endif		/* !MY_TOOL_TAB_H_ */
