/*
** elcrypt.h for elcrypt in /home/tran_0/rendu/elcrypt
**
** Made by David Tran
** Login   <tran_0@epitech.net>
**
** Started on  Fri Mar 13 21:05:54 2015 David Tran
** Last update Sat Mar 14 00:11:38 2015 David Tran
*/

#ifndef ELCRYPT_H_
# define ELCRYPT_H_

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include "error.h"

# define BLOCK_SIZE     8

typedef union		u_key
{
  unsigned long int	key;
  unsigned char		c_key[64];
  unsigned int		i_key[2];
}			t_key;

typedef struct		s_crypt
{
  char			crypted;
  int			fdin;
  int			fdout;
  t_key			key;
  t_key			tmp;
}			t_crypt;

#endif /* !ELCRYPT_H_ */
