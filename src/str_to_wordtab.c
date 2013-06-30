/*
** str_to_wordtab.c for decode-tools in /home/bondot_e/Epitech/2017/projets_perso/decode-toolkit
**
** Made by bondot_e
** Login   <bondot_e@epitech.net>
**
** Started on  Sun Jun 30 11:56:40 2013 bondot_e
** Last update Sun Jun 30 12:38:08 2013 bondot_e
*/

#include "decode.h"

int		cut_words(char *s)
{
  int		i;
  int		count;

  i = 0;
  count = 1;
  while (s[i])
    {
      if (s[i] == ' ')
	{
	  s[i] = '\0';
	  count++;
	}
      i++;
    }
  return (count);
}

void		print_wordtab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    {
      printf("tab[%d]: %s\n", i, tab[i]);
      i++;
    }
}

char		**str_to_wordtab(char *s)
{
  int		i;
  int		j;
  int		count;
  char		*s_cpy;
  char		**res;

  i = 0;
  j = 0;
  s_cpy = 0;
  if (s == NULL)
    return (NULL);
  s_cpy = strdup(s);
  count = cut_words(s_cpy);
  res = malloc(sizeof(char *) * (count + 1));
  if (res == NULL)
    print_err("Error: malloc failed in str_to_wordtab.c\n");
  while (count > 0)
    {
      res[j] = strdup(&s_cpy[i]);
      while (s_cpy[i]) i++;
      i++;
      j++;
      count--;
    }
  res[j] = 0;
  free(s_cpy);
  return (res);
}
