/*
** elcrypt.h for elcrypt in /home/tran_0/rendu/elcrypt
** 
** Made by David Tran
** Login   <tran_0@epitech.net>
** 
** Started on  Fri Mar 13 21:05:54 2015 David Tran
** Last update Fri Mar 13 21:49:02 2015 David Tran
*/

#ifndef ELCRYPT_H_
# define ELCRYPT_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef union		u_key
{
  unsigned long int	key;
  unsigned char		c_key[64];
  unsigned int		i_key[16];
}			t_key;

typedef struct		s_crypt
{
  char			crypt;
  int			fdin;
  int			fdout;
  t_key			key;
}			t_crypt;

#endif /* !ELCRYPT_H_ */
