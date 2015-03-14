/*
** main.c for elcrypt in /home/tran_0/rendu/elcrypt
** 
** Made by David Tran
** Login   <tran_0@epitech.net>
** 
** Started on  Fri Mar 13 21:04:57 2015 David Tran
** Last update Sat Mar 14 15:45:38 2015 David Tran
*/

#include "elcrypt.h"

int		check_filled(t_crypt *crypt)
{
  if (crypt->crypted == -1 || crypt->key.key == 0 ||
      crypt->fdin == 0 || crypt->fdout == 0)
    return (-1);
  return (EXIT_SUCCESS);
}

int		main(int ac, char **av)
{
  t_crypt	crypt;

  if (ac != 8)
    return (ERROR(USAGE));
  crypt.crypted = -1;
  crypt.key.key = 0;
  crypt.fdin = 0;
  crypt.fdout = 0;
  if (call_option(ac, av, &crypt) < 0 || check_filled(&crypt) == -1)
    return (ERROR(USAGE));
  return (EXIT_SUCCESS);
}
