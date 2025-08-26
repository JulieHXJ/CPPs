# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junjun <junjun@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/25 12:16:46 by junjun            #+#    #+#              #
#    Updated: 2025/08/25 12:29:36 by junjun           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= whatever

CXX		= c++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS		= main.cpp

OBJS		= $(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o:		%.cpp
		$(CXX) $(CXXFLAGS) -c $< -o $@

clean:		
	rm -f $(OBJS)

fclean:		clean
	rm -f $(NAME)
		
re:		fclean all

.PHONY:		all clean fclean re