/*
** verboseme.c for decode in /home/bondot_e/workspace/Decode
**
** Made by bondot_e
** Login   <bondot_e@epitech.net>
**
** Started on  Sat Jun 29 10:18:17 2013 bondot_e
** Last update Sun Jun 30 12:39:29 2013 bondot_e
*/

#include "decode.h"

int		find_occurence(char *str)
{
  int		i;
  int		count;
  char		*str_cpy;
  char		**tab_char;
  char		occ[30 + 1];

  i = 0;
  count = 0;
  str_cpy = strdup(str);
  tab_char = str_to_wordtab(str_cpy);
  printf("What is the word ? ");
  scanf("%30s", occ);
  while (tab_char[i])
    {
      if (!strcmp(occ, tab_char[i]))
	count++;
      i++;
    }
  printf("Occurences: %d\n", count);
  free(str_cpy);
  free_tabchar(tab_char);
  return (count);
}

void		print_text(char **tab)
{
  int		i;

  i = 1;
  printf("\n\n----------------------------------------------\n\n");
  printf("%s", tab[0]);
  while (tab[i])
    {
      printf(" %s", tab[i]);
      i++;
    }
  printf("\n\n----------------------------------------------\n\n");
}

int		show_occurence(char *str)
{
  int		i;
  char		*str_cpy;
  char		**tab_char;
  char		*tmp;
  char		occ[30 + 1];

  i = 0;
  str_cpy = strdup(str);
  tab_char = str_to_wordtab(str_cpy);
  printf("What is the world ? ");
  scanf("%30s", occ);
  while (tab_char[i])
    {
      if (!strcmp(occ, tab_char[i]))
	{
	  tmp = malloc(strlen("\033[36m") + strlen(tab_char[i]) + strlen("\033[00m") + 1);
	  strcpy(tmp, "\033[36m");
	  strcat(tmp, tab_char[i]);
	  strcat(tmp, "\033[00m");
	  tab_char[i] = strdup(tmp);
	}
      i++;
    }
  print_text(tab_char);
  free(str_cpy);
  free(tmp);
  free_tabchar(tab_char);
  return (0);
}

int		count_letters(char *str)
{
  if (str != NULL)
    return (strlen(str));
  return (0);
}

int		count_words(char *str)
{
  int		i;
  int		count;

  i = 0;
  count = 1;
  if (str == NULL) return (0);
  if (strlen(str) == 0) return (0);
  while (str[i])
    {
      if (str[i] == ' ')
	count++;
      i++;
    }
  return (count);
}

void		analysis(int opt, char *str)
{
  int		i;
  int		(*funct[4])(char *) = {
    &count_words,
    &count_letters,
    &find_occurence,
    &show_occurence
  };

  i = 0;
  opt = 0;
  (void) opt;
  printf("\t1 - Count words\n"
	 "\t2 - Count letters\n"
	 "\t3 - Find some occurences\n"
	 "\t4 - Show occurences\n"
	 "\t5 - All informations\n\n"
	 "What do you want to do ? ");
  scanf("%d", &i);
  if (i == 5)
    printf("Words  : %d\n"
	   "Letters: %d", funct[0](str), funct[1](str));
  else
    funct[i - 1](str);
}
