##
## Makefile for allum1 in /home/andriv_e/Documents/allum1
## 
## Made by Edwin
## Login   <andriv_e@epitech.net>
## 
## Started on  Thu Feb  7 13:55:33 2013 Edwin
## Last update Sun Feb 17 23:19:04 2013 theSilverNeph
##

SRCS	=	main.c

OBJS	=	$(SRCS:.c=.o)

CC	=	gcc

NAME	=	allum1

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) -lcurses

clean	:
		rm -rf $(OBJS)

fclean	:	clean
		rm -rf $(NAME)

re	:	fclean all