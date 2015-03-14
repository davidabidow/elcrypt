/*
** options_tab.c for options_tab in /home/tran_0/rendu/elcrypt
** 
** Made by David Tran
** Login   <tran_0@epitech.net>
** 
** Started on  Sat Mar 14 02:04:33 2015 David Tran
** Last update Sat Mar 14 18:22:07 2015 David Tran
*/

#include "elcrypt.h"

int	option_filein(t_crypt *crypt, char *data)
{
  if ((crypt->fdin = open(data, O_RDONLY)) == -1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int	option_fileout(t_crypt *crypt, char *data)
{
  if ((crypt->fdout = open(data, O_RDWR | O_CREAT, 0644)) == -1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int	option_decryp(t_crypt *crypt, char *data __attribute__((unused)))
{
  if (crypt->crypted != -1)
    return (EXIT_FAILURE);
  crypt->crypted = 1;
  return (EXIT_SUCCESS);
}

int			option_key(t_crypt *crypt, char *data)
{
  int			i;
  unsigned long int	tmp;

  tmp = 0;
  if (!data || strlen(data) < 2 || crypt->key.key != 0)
    return (EXIT_FAILURE);
  crypt->key.key = strtoul(&data[2], NULL, strlen(data) - 2);
  //  printf("%llx\n", (unsigned long long)crypt->key.key);
  i = 0;
  while (i < 64)
    {
      //  printf("i : %d, %d\n", i, crypt->key.key >> 63);
      //printf("%lu\n", tmp);
      if (crypt->key.key >> 63 == 1 && i % 8 != 7)
	tmp += 1;
      crypt->key.key <<= 1;
      if (i % 8 == 7)
	{
	  //	  printf("entered, skipping\n");
	  crypt->key.key <<= 1;
	}
      if (tmp != 63)
	tmp <<= 1;
      i++;
    }
  crypt->key.key = tmp;
  // printf("%llx\n", (unsigned long long)tmp);
  return (EXIT_SUCCESS);
}

int	option_cryp(t_crypt *crypt, char *data __attribute__((unused)))
{
  if (crypt->crypted != -1)
    return (EXIT_FAILURE);
  crypt->crypted = 0;
  return (EXIT_SUCCESS);
}
