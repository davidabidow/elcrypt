/*
** Feistel.c for Feistel in /home/tran_0/rendu/elcrypt
**
** Made by David Tran
** Login   <tran_0@epitech.net>
**
** Started on  Fri Mar 13 23:11:08 2015 David Tran
** Last update Sat Mar 14 23:58:49 2015 David Tran
*/

#include "elcrypt.h"

int                     rotate_key(t_crypt *crypt, int tour)
{
  int                   c1;
  int                   c2;

  c1 = 0;
  crypt->second.key = crypt->key.key;
  while (c1 <= tour)
    {
      c2 = 0;
      while (c2 < 4)
        {
          if ((crypt->second.key >> 63) == 1)
            crypt->second.key |= 1;
          crypt->second.key <<= 1;
          c2++;
        }
      c1++;
    }
  return (EXIT_SUCCESS);
}

void	make_turns(t_crypt *crypt)
{
  int	i;

  i = 0;
  while (i < 8)
    {
      rotate_key(crypt, (crypt->crypted == 1) ? 7 - i : i);
      (crypt->crypted == 1) ? decrypt(crypt, i) : encrypt(crypt, i);
      // Feistel
      i++;
    }
}
