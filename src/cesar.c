/*
** cesar.c for decode in /home/bondot_e/rendu/projets_perso/decode_toolkit
** 
** Made by etienne bondot
** Login   <bondot_e@epitech.net>
** 
** Started on  Wed Jun  5 11:53:57 2013 etienne bondot
** Last update Wed Jun  5 16:12:23 2013 etienne bondot
*/

#include "decode.h"

void		cesar_encode(char *str)
{
  int		i;
  int		decalage;

  i = 0;
  printf("Decalage : ");
  scanf("%d", &decalage);
  while (str[i])
    {
      if (isalpha(str[i]))
	  str[i] = (str[i] + decalage - 'a') + 'a';
      i++;
    }
  printf("Encode string : %s\n", str);
}

void		cesar_decode(char *str)
{
  int		i;
  int		j;

  i = 1;
  while (i < 26)
    {
      j = 0;
      while (str[j])
	{
	  if (str[j] == 'Z' || str[j] == 'z')
	    str[j] -= 25;
	  else if ((str[j] >= 'a' && str[j] < 'z') ||
		   (str[j] >= 'A' && str[j] < 'Z'))
	    str[j]++;
	  j++;
	}
      printf("Decode %d:\n%s\n\n", i, str);
      i++;
    }
}

void		cesar(int opt, char *str)
{
  if (opt == ENCODE)
    {
      printf("Encryption... please wait...\n");
      cesar_encode(str);
      printf("Encryption done.\n");
    }
  else if (opt == DECODE)
    {
      printf("Decryption... please wait...\n");
      cesar_decode(str);
      printf("Decryption done.\n");
    }
  else
    return;
}
