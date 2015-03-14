/*
** block_generator.c for elcrypt in /home/guiz/rendu
**
** Made by Guillaume Briard
** Login   <guiz@epitech.net>
**
** Started on  Fri Mar  11 23:43:34 2015 Guillaume Briard
** Last update Sat Mar 14 18:37:31 2015 David Tran
*/

#include "elcrypt.h"

void		fill_key(t_crypt *crypt, int beg, int pad)
{
  while (beg < 8)
    {
      crypt->tmp.c_key[beg] = pad;
      beg++;
    }
}

int             get_block(t_crypt *crypt)
{
  int           rd;
  int           pad;
  int           size;

  size = 0;
  while ((rd = read(crypt->fdin, &crypt->tmp.key, BLOCK_SIZE)) > 0)
    {
      if (rd < BLOCK_SIZE)
        {
          pad = BLOCK_SIZE - rd;
	  fill_key(crypt, 7 - pad, pad);
          if (write(crypt->fdout, &crypt->tmp.c_key[7 - pad], pad) == -1)
            return (EXIT_FAILURE);
        }
      if (write(crypt->fdout, &crypt->tmp.key, rd) == -1)
        return (EXIT_FAILURE);
      size += rd;
      rd = 0;
    }
  if ((size % BLOCK_SIZE) == 0)
    {
      fill_key(crypt, 8, BLOCK_SIZE);
      if (write(crypt->fdout, &crypt->tmp.c_key[0], BLOCK_SIZE) == -1)
        return (EXIT_FAILURE);
    }
}
