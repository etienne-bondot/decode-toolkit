/*
** utils_1.c for decode in /home/bondot_e/rendu/projets_perso/decode_toolkit
**
** Made by etienne bondot
** Login   <bondot_e@epitech.net>
**
** Started on  Wed Jun  5 11:57:39 2013 etienne bondot
** Last update Sun Jun 30 12:16:39 2013 bondot_e
*/

#include "decode.h"

int		is_in_str(char c, char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (c == str[i])
	return (1);
      i++;
    }
  return (0);
}

void		free_tabchar(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}
