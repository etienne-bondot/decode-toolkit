/*
** main.c for decode in /home/bondot_e/rendu/projets_perso/decode_toolkit
** 
** Made by etienne bondot
** Login   <bondot_e@epitech.net>
** 
** Started on  Wed Jun  5 10:54:11 2013 etienne bondot
** Last update Wed Jun  5 12:17:35 2013 etienne bondot
*/

#include "decode.h"

int		main(int ac, char **av)
{
  int		code;
  t_args	args;

  code = parse_options(ac, av, &args);
  printf("Votre text : %s\n"				\
	 "Option     : %d\n", args.str, args.opt);
  option[code].function(args.opt, args.str);
  return (0);
}
