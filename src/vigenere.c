/*
** vigrnere.c for decode in /home/bondot_e/rendu/projets_perso/decode_toolkit/src
** 
** Made by etienne bondot
** Login   <bondot_e@epitech.net>
** 
** Started on  Wed Jun  5 15:51:45 2013 etienne bondot
** Last update Wed Jun  5 21:29:10 2013 etienne bondot
*/

#include "decode.h"

int		get_ind(char c)
{
  int		i;
  char		str[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  i = 0;
  while (str[i])
    {
      if (c == str[i])
	return (i);
      i++;
    }
  return (0);
}

void		upper_str(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] >= 'a' && str[i] <= 'z')
	str[i] -= 32;
      i++;
    }
}

int		find_column_in_table(int ind_e, char c)
{
  int		i;

  i = 0;
  while (vigenere_table[ind_e][i])
    {
      if (vigenere_table[ind_e][i] == c)
	return (i);
      i++;
    }
  return (0);
}

void		vigenere_encode(char *str)
{
  int		i;
  char		*key;
  char		*encode;
  int		ind_e;
  int		ind_c;

  i = 0;
  if ((key = malloc(strlen(str) + 1)) == NULL)
    print_err("Err: malloc failed.\n");
  printf("Enter the key : ");
  fgets(key, 4096, stdin);
  upper_str(key);
  upper_str(str);
  if ((encode = malloc(strlen(key) + 1)) == NULL)
    print_err("Err: malloc failed.\n");
  while (str[i])
    {
      if (isalpha(str[i]))
	{
	  ind_c = get_ind(str[i]);
	  ind_e = get_ind(key[i]);
	  encode[i] = vigenere_table[ind_e][ind_c];
	}
      else
	encode[i] = str[i];
      i++;
    }
  printf("Encode string: %s\n", encode);
  free(encode);
}

void		vigenere_decode(char *str)
{
  int		i;
  char		*key;
  char		*decode;
  int		ind_e;
  int		ind_c;

  i = 0;
  if ((key = malloc(strlen(str) + 1)) == NULL)
    print_err("Err: malloc failed.\n");
  printf("Enter the key : ");
  fgets(key, 4096, stdin);
  upper_str(key);
  upper_str(str);
  if ((decode = malloc(strlen(key) + 1)) == NULL)
    print_err("Err: malloc failed.\n");
  while (str[i])
    {
      if (isalpha(str[i]))
	{
	  ind_e = get_ind(key[i]);
	  ind_c = find_column_in_table(ind_e, str[i]);
	  decode[i] = vigenere_table[0][ind_c];
	}
      else
	decode[i] = str[i];
      i++;
    }
  printf("Decode string: %s\n", decode);
  free(decode);  
}

void		vigenere(int opt, char *str)
{
  if (opt == ENCODE)
    {
      printf("Encryption... please wait...\n");
      vigenere_encode(str);
      printf("Encryption done.\n");
    }
  else if (opt == DECODE)
    {
      printf("Decryption... please wait...\n");
      vigenere_decode(str);
      printf("Decryption done.\n");
    }
  else
    return;
}
