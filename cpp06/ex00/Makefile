# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junjun <junjun@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/21 17:13:40 by junjun            #+#    #+#              #
#    Updated: 2025/08/22 23:29:00 by junjun           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = convert

SRC = ScalarConverter.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(COMPILER) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(COMPILER) $(CFLAGS) -o $@ -c $<

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re