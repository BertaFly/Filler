# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/15 13:16:28 by inovykov          #+#    #+#              #
#    Updated: 2018/03/06 21:14:12 by inovykov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = inovykov.filler.

FLAGS = -Wall -Werror -Wextra

DIR_S = src

HEADER = includes

SOURCES = 

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(SOURCES:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@cp ./libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "executable file is ready"

%.o : $(DIR_S)/%.c
	@gcc $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@make clean -C libft/
	@/bin/rm -f $(OBJS)
	@echo "objects were removed"

fclean: clean
	@make fclean -C libft/
	@/bin/rm -f $(NAME)
	@echo "executable file was removed"

re: fclean all