/*
** options.c for elcrypt in /home/guiz/rendu
**
** Made by Guillaume Briard
** Login   <guiz@epitech.net>
**
** Started on  Fri Mar  11 23:43:34 2015 Guillaume Briard
** Last update Sat Mar 14 16:32:07 2015 David Tran
*/

#include "elcrypt.h"

void	fill_tab(t_crypt *crypt)
{
  crypt->funcs[0] = &option_decryp;
  crypt->option[0] = 'd';
  crypt->funcs[1] = &option_cryp;
  crypt->option[1] = 'e';
  crypt->funcs[2] = &option_filein;
  crypt->option[2] = 'f';
  crypt->funcs[3] = &option_fileout;
  crypt->option[3] = 'o';
  crypt->funcs[4] = &option_key;
  crypt->option[4] = 'k';
}

int	call_option(int ac, char **av, t_crypt *crypt)
{
  int	i;
  int	j;

  i = 1;
  printf("Options check...\n");
  fill_tab(crypt);
  while (i < ac)
    {
      printf("%d, %s\n", i, av[i]);
      j = 0;
      if (strlen(av[i]) != 2)
	return (-1);
      while (j < 5)
	{
	  if (av[i][1] == crypt->option[j])
	    if (crypt->funcs[j](crypt, av[i + 1]) == EXIT_FAILURE)
	      return (-1);
	  j++;
	}
      if (i != 1)
	i += 1;
      i += 1;
    }
  printf("Options checked...\n");
  return (EXIT_SUCCESS);
}
