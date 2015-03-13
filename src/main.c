/*
** main.c for elcrypt in /home/tran_0/rendu/elcrypt
** 
** Made by David Tran
** Login   <tran_0@epitech.net>
** 
** Started on  Fri Mar 13 21:04:57 2015 David Tran
** Last update Sat Mar 14 00:17:23 2015 David Tran
*/

#include "elcrypt.h"

int	main(int ac, char **av __attribute__((unused)))
{
  if (ac != 8)
    {
      printf("USAGE : %s [-d / -e] -f [infile] -o [fileout] -k [key]\n");
      return (EXIT_FAILURE);
    }
  
  return (EXIT_SUCCESS);
}
