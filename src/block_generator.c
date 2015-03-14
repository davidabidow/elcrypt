/*
** block_generator.c for elcrypt in /home/guiz/rendu
**
** Made by Guillaume Briard
** Login   <guiz@epitech.net>
**
** Started on  Fri Mar  11 23:43:34 2015 Guillaume Briard
** Last update Sun Mar 15 00:24:11 2015 David Tran
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

void		last_check(t_crypt *crypt, int rd, int *size)
{
  int		pad;

  pad = BLOCK_SIZE - rd;
  fill_key(crypt, 7 - pad, pad);
  make_turns(crypt);
  if (write(crypt->fdout, &crypt->tmp.key, BLOCK_SIZE) == -1)
    return ;
  *size += rd;
}

void		get_block(t_crypt *crypt)
{
  int		rd;
  int		size;

  size = 0;
  while ((rd = read(crypt->fdin, &crypt->tmp.key, BLOCK_SIZE)) > 0)
    {
      if (rd < BLOCK_SIZE)
	{
	  last_check(crypt, rd, &size);
	  break;
	}
      make_turns(crypt);
      if (write(crypt->fdout, &crypt->tmp.key, rd) == -1)
        return ;
      size += rd;
      rd = 0;
    }
  if ((size % BLOCK_SIZE) == 0)
    {
      fill_key(crypt, 0, BLOCK_SIZE);
      make_turns(crypt);
      if (write(crypt->fdout, &crypt->tmp.key, BLOCK_SIZE) == -1)
        return ;
    }
}
