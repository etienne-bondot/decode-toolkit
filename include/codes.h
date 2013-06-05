/*
** codes.h for decode in /home/bondot_e/rendu/projets_perso/decode_toolkit/src
** 
** Made by etienne bondot
** Login   <bondot_e@epitech.net>
** 
** Started on  Wed Jun  5 16:15:07 2013 etienne bondot
** Last update Wed Jun  5 16:17:23 2013 etienne bondot
*/

#ifndef _CODES_H_
# define _CODES_H_

/*
** cesar.c
*/
void		cesar_decrypt(char *);
void		cesar_decrypt(char *);
void		cesar(int, char *);

/*
** vigenere.c
*/
int		get_ind(char);
void		upper_str(char *);
void		vigenere_encode(char *);
void		vigenere_decode(char *);
void		vigenere(int, char *);

#endif /* !_CODES_H_ */
