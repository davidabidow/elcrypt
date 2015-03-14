/*
** encrypt.c for encrypt in /home/tran_0/rendu/elcrypt
** 
** Made by David Tran
** Login   <tran_0@epitech.net>
** 
** Started on  Sat Mar 14 21:44:10 2015 David Tran
** Last update Sat Mar 14 23:59:01 2015 David Tran
*/

#include "elcrypt.h"

void	encrypt(t_crypt *crypt, int i)
{
  if (i % 2 == 0)
    crypt->tmp.i_key[0] ^= crypt->second.i_key[1];
  else
    crypt->tmp.i_key[1] ^= crypt->second.i_key[1];
}

