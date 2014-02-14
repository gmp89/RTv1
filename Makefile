#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/11 12:40:38 by gpetrov           #+#    #+#              #
#    Updated: 2014/02/14 15:49:34 by gpetrov          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= RTv1
FILES	= main.c ft_mlx.c tools.c draw.c vector.c
SRCS	= $(addprefix src/, $(FILES))
OBJS	= $(SRCS:src/%.c=.obj/%.o)
INC		= -I includes -I libft/includes
FLAGS	= -Wall -Wextra -Werror
LIB		= -L libft -lft

all: $(NAME)
$(NAME): $(OBJS)
	make -C libft
	cc $(FLAGS) $(SRCS) -o $(NAME) $(INC) $(LIB) \
	-L /usr/X11/lib -lmlx -lXext -lX11
.obj/%.o: src/%.c
	mkdir -p .obj
	cc -c $< -o $@ $(FLAGS) $(INC)
gdb:
	make -C libft
	cc -g $(FLAGS) $(SRCS) -o $(NAME) $(INC) $(LIB) \
	-L /usr/X11/lib -lmlx -lXext -lX11
	gdb $(NAME)
clean:
	rm -rf .obj
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all gdb clean fclean re
