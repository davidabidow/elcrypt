/*
** Feistel.c for Feistel in /home/tran_0/rendu/elcrypt
**
** Made by David Tran
** Login   <tran_0@epitech.net>
**
** Started on  Fri Mar 13 23:11:08 2015 David Tran
** Last update Sun Mar 15 08:37:48 2015 David Tran
*/

#include "elcrypt.h"

int                     rotate_key(t_crypt *crypt, int tour)
{
  int                   c1;
  int                   c2;

  c1 = 0;
  crypt->second.key = crypt->key.key;
  while (c1 < tour)
    {
      c2 = 0;
      while (c2 < 4)
        {
          if ((crypt->second.key >> 63) == 1)
	    {
	      crypt->second.key <<= 1;
	      crypt->second.key |= 1;
	    }
	  else
	    crypt->second.key <<= 1;
          c2++;
        }
      c1++;
    }
  crypt->second.key <<= 32;
  crypt->second.key >>= 32;
  return (EXIT_SUCCESS);
}

void		make_turns(t_crypt *crypt)
{
  int		i;
  unsigned int	nb1;
  unsigned int	nb2;

  i = 0;
  nb1 = crypt->tmp.key >> 32;
  nb2 = crypt->tmp.key << 32 >> 32;
  while (i < 8)
    {
      //      printf("%llu\n", crypt->second.key);
      rotate_key(crypt, (crypt->crypted == 1) ? 7 - i : i);
      (crypt->crypted == 1) ? decrypt(crypt, i, &nb1, &nb2) :
	encrypt(crypt, i, &nb1, &nb2);
      // Feistel
      i++;
    }
  crypt->tmp.key = 0;
  crypt->tmp.key += nb1;
  crypt->tmp.key <<= 32;
  crypt->tmp.key |= nb2;
}
