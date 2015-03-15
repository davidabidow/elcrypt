/*
** decrypt.c for decrypt in /home/tran_0/rendu/elcrypt
** 
** Made by David Tran
** Login   <tran_0@epitech.net>
** 
** Started on  Sat Mar 14 21:47:58 2015 David Tran
** Last update Sun Mar 15 08:37:04 2015 David Tran
*/

#include "elcrypt.h"

void	decrypt(t_crypt *crypt, int i,
		unsigned int *nb1, unsigned int *nb2)
{
  int   r_tmp;
  int   l_tmp;

  r_tmp = *nb2;
  l_tmp = *nb1;
  if (i % 2 == 1)
    {
      r_tmp ^= crypt->second.key;
      *nb1 ^= r_tmp;
    }
  else
    {
      l_tmp ^= crypt->second.key;
      *nb2 ^= l_tmp;
    }
}
