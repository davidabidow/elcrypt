##
## Makefile for Makefile in /home/tran_0/rendu/elcrypt
## 
## Made by David Tran
## Login   <tran_0@epitech.net>
## 
## Started on  Fri Mar 13 21:01:30 2015 David Tran
## Last update Fri Mar 13 21:07:50 2015 David Tran
##

CC=	gcc

SRCS=	src/main.c	\

OBJS=	$(SRCS:.c=.o)

RM=	rm -rf

CFLAGS=	-W -Wall -ansi -pedantic -I./include

NAME=	elcrypt

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
