# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/25 12:16:46 by junjun            #+#    #+#              #
#    Updated: 2025/09/09 15:34:23 by xhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= array

CXX		= c++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++17

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
		
re:		fclean 
		@$(MAKE) all

.PHONY:		all clean fclean re