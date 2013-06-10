/*
** error.c for decode in /home/bondot_e/rendu/projets_perso/decode_toolkit
** 
** Made by etienne bondot
** Login   <bondot_e@epitech.net>
** 
** Started on  Wed Jun  5 11:15:29 2013 etienne bondot
** Last update Mon Jun 10 11:20:27 2013 etienne bondot
*/

#include "decode.h"
#define	L_BUFF	4096

void		print_err(char *err_msg)
{
  fprintf(stderr, "%s", err_msg);
  usage();
}

void		usage()
{
  FILE		*f;
  char		buff[L_BUFF];

  f = fopen("./src/usage", "r");
  if (f == NULL)
    {
      perror("usage(): ");
      exit(EXIT_FAILURE);
    }
  while (fgets(buff, L_BUFF, f) != NULL)
    {
      printf("%s", buff);
      memset(buff, 0x0, L_BUFF);
    }
  fclose(f);
  exit(EXIT_FAILURE);
}
