/*
** parse_options.c for decode in /home/bondot_e/rendu/projets_perso/decode_toolkit
** 
** Made by etienne bondot
** Login   <bondot_e@epitech.net>
** 
** Started on  Wed Jun  5 10:57:55 2013 etienne bondot
** Last update Mon Jun 10 10:48:22 2013 etienne bondot
*/

#define _POSIX_C_SOURCE	200809L
#include "decode.h"

void		get_opt_param(char **av, t_args *args)
{
  if (!strcmp(av[2], "--encode") && strlen(av[2]) == strlen("--encode"))
    args->opt = ENCODE;
  else if (!strcmp(av[2], "--decode") && strlen(av[2]) == strlen("--decode"))
    args->opt = DECODE;
  else
    print_err("Err: invalid command.\n");  
}

void		get_str_param(char **av, t_args *args)
{
  if (av[3][0] != '-')
    args->str = strdup(av[3]);
  else
    print_err("Err: invalid command.\n");
}

int		parse_options(int ac, char **av, t_args *args)
{
  int		i;
  int		found;

  i = 0;
  found = 0;
  if (ac != 4)
    {
      ac < 4 ?
	print_err("Err: too few arguments.\n") : 
	print_err("Err: too many arguments.\n");
    }
  while (option[i].param && !found)
    {
      if (!strcmp(av[1], option[i].param) && strlen(av[1]) == 2)
	{
	  get_opt_param(av, args);
	  get_str_param(av, args);
	  return (i);
	}
      i++;
    }
  print_err("Err: couldn't find [option].\n");
  return (-1);
}
