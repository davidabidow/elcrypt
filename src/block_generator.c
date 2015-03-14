/*
** block_generator.c for elcrypt in /home/guiz/rendu
**
** Made by Guillaume Briard
** Login   <guiz@epitech.net>
**
** Started on  Fri Mar  11 23:43:34 2015 Guillaume Briard
** Last update Sat Mar 14 18:23:47 2015 David Tran
*/

#include "elcrypt.h"

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
          &crypt->tmp.key = memset(&crypt->tmp.c_key[7 - pad], pad, pad);
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
      &crypt->tmp.key = memset(&crypt->tmp.c_key[0], 8, BLOCK_SIZE);
      if (write(crypt->fdout, &crypt->tmp.c_key[0], BLOCK_SIZE) == -1)
        return (EXIT_FAILURE);
    }
}
