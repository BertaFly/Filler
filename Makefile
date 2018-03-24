# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/16 12:17:53 by abodnar           #+#    #+#              #
#    Updated: 2018/03/21 16:13:06 by inovykov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = inovykov.filler

LIB = libft.a

SRCS = test.c

OBJECTS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o : %.c
	@gcc -I. -I./libft $(FLAGS) -c $< -o $@

$(NAME): $(LIB) $(OBJECTS) ./includes/*.h
	@gcc -o $@ -I. -I./libft $(OBJECTS) $(LIB)
	@echo "READY TO PLAY"
	
$(LIB):
	@make -C ./libft/
	@cp ./libft/libft.a .

clean:
	@make fclean -C ./libft
	@rm -f *.o
	@rm -f libft.a
	
fclean: clean
	@rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re
