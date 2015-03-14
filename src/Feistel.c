/*
** Feistel.c for Feistel in /home/tran_0/rendu/elcrypt
**
** Made by David Tran
** Login   <tran_0@epitech.net>
**
** Started on  Fri Mar 13 23:11:08 2015 David Tran
** Last update Sat Mar 14 15:47:00 2015 David Tran
*/

#include "elcrypt.h"

int                     rotate_key(t_crypt *crypt, int tour)
{
  int                   c1;
  int                   c2;

  c1 = 0;
  c2 = 0;
  crypt->tmp.key = crypt->key.key;
  while (c1 <= tour)
    {
      while (c2 < 4)
        {
          if ((crypt->tmp.key >> 63) == 1)
            crypt->tmp.key |= 1;
          crypt->tmp.key << 1;
          c2++;
        }
      c1++;
    }
  return (EXIT_SUCCESS);
}

int	build_key(t_crypt *crypt, int i)
{
}

void	make_turns(t_crypt *crypt)
{
  int	i;
  int	second;

  i = 0;
  while (i < 8)
    {
      rotate_key(crypt->key, i);
      i++;
      second = crypt->tmp.i_key[1];
      // Feistel
    }
}
