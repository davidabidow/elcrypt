/*
** decrypt.c for decrypt in /home/tran_0/rendu/elcrypt
** 
** Made by David Tran
** Login   <tran_0@epitech.net>
** 
** Started on  Sat Mar 14 21:47:58 2015 David Tran
** Last update Sun Mar 15 04:07:56 2015 David Tran
*/

#include "elcrypt.h"

void	decrypt(t_crypt *crypt, int i)
{
  int   r_tmp;
  int   l_tmp;

  r_tmp = crypt->tmp.i_key[1];
  l_tmp = crypt->tmp.i_key[0];
  if (i % 2 == 1)
    {
      r_tmp ^= crypt->second.i_key[1];
      crypt->tmp.i_key[0] ^= r_tmp;
    }
  else
    {
      l_tmp ^= crypt->second.i_key[1];
      crypt->tmp.i_key[1] ^= l_tmp;
    }
}
