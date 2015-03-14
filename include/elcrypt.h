/*
** elcrypt.h for elcrypt in /home/tran_0/rendu/elcrypt
**
** Made by David Tran
** Login   <tran_0@epitech.net>
**
** Started on  Fri Mar 13 21:05:54 2015 David Tran
** Last update Sat Mar 14 15:45:03 2015 David Tran
*/

#ifndef ELCRYPT_H_
# define ELCRYPT_H_

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <sys/stat.h>
# include "error.h"

# define BLOCK_SIZE     8

typedef union		u_key
{
  unsigned long int	key;
  unsigned char		c_key[8];
  unsigned int		i_key[2];
}			t_key;

typedef struct		s_crypt
{
  char			crypted;
  int			fdin;
  int			fdout;
  t_key			key;
  t_key			tmp;
  int			(*funcs[5])(struct s_crypt *, char *);
  char			option[5];
}			t_crypt;

int			option_filein(t_crypt *, char *);
int			option_fileout(t_crypt *, char *);
int			option_decryp(t_crypt *, char *);
int			option_key(t_crypt *, char *);
int			option_cryp(t_crypt *, char *);

#endif /* !ELCRYPT_H_ */
