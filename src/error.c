/*
** error.c for decode in /home/bondot_e/rendu/projets_perso/decode_toolkit
** 
** Made by etienne bondot
** Login   <bondot_e@epitech.net>
** 
** Started on  Wed Jun  5 11:15:29 2013 etienne bondot
** Last update Wed Jun  5 11:27:35 2013 etienne bondot
*/

#include "decode.h"

void		print_err(char *err_msg)
{
  fprintf(stderr, "%s", err_msg);
  usage();
}

void		usage()
{
  fprintf(stdin, "usage");
  exit(EXIT_FAILURE);
}
