# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/10 19:55:44 by kbui              #+#    #+#              #
#    Updated: 2018/11/12 16:26:14 by kbui             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CFLAGS = -Wall -Wextra -Werror
CC = gcc

SRCS_DIR = srcs/
OBJS_DIR = objs/

INCS = -I includes/
SRCS = $(wildcard $(SRCS_DIR)*.c)
LIBS = libft/libft.a
OBJS = $(patsubst srcs/%.c, %.o, $(SRCS))


all: $(NAME)

$(NAME):
	@make -C libft
	@$(CC) -g $(CFLAGS) -c $(SRCS) $(INCS)
	@$(CC) -g -o $(NAME) $(OBJS) $(LIBS)
	@mkdir -p $(OBJS_DIR)
	@mv $(OBJS) $(OBJS_DIR)

clean:
	@rm -rf $(OBJS_DIR)
	@make clean -C libft

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft

re: fclean all

.PHONY: all clean fclean re