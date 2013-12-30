#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 15:09:23 by cmehay            #+#    #+#              #
#    Updated: 2013/12/30 10:50:02 by cmehay           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = pipex
SRCDIR = srcs
HEADDIR = includes
HEAD = $(NAME).h
HEADFILES = $(addprefix $(HEADDIR)/, $(HEAD))
SRC = main.c
SRCFILES = $(addprefix $(SRCDIR)/, $(SRC))
LIB = libft.a
LIBDIR = libft
LIBFILES = $(addprefix $(LIBDIR)/, $(LIB))
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(LIB): $(LIBFILES)

$(NAME): $(OBJ) $(LIBFILES)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIBDIR) -lft

$(OBJ): $(SRCFILES)
	$(CC) $(CFLAGS) -I$(HEADDIR) -c $(SRCFILES)

$(LIBFILES):
	$(MAKE) -C $(LIBDIR) $(LIB)

.PHONY: all clean fclean re

clean:
	/bin/rm -f $(OBJ)
	$(MAKE) -C $(LIBDIR) clean

fclean: clean
	/bin/rm -f $(NAME)
	$(MAKE) -C $(LIBDIR) fclean

re: fclean all
