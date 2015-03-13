/*
** error.h for elcrypt in /home/guiz/rendu
**
** Made by Guillaume Briard
** Login   <guiz@epitech.net>
**
** Started on  Fri Mar  11 23:43:34 2015 Guillaume Briard
** Last update Sat Mar  12 20:46:02 2015 Guillaume Briard
*/

#ifndef ERROR_H_
# define ERROR_H_

/*
** Error macros
*/
# define USAGE  "Usage : ./elcrypt -d/-e -f [IN-FILE] -o [OUT-FILE] -k [KEY]\n"

/*
** Call error macros
*/
# define ERROR(m) dprintf(2, "%s", m)

#endif /* !ERROR_H_ */
