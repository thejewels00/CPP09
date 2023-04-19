# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchennak <jchennak@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/19 16:45:25 by jchennak          #+#    #+#              #
#    Updated: 2023/04/19 16:46:59 by jchennak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
NAME = btc
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS =  main.cpp

all : $(NAME)

OBJECT_FILE = $(SRCS:%.cpp=%.o)

$(NAME) : $(OBJECT_FILE) 
	$(CC) $(CPPFLAGS) $(OBJECT_FILE) -o $(NAME)
	@printf "\033[1;33m****Program compiled Succesfully ! ****\033[0m\n"

clean :
	@rm -rf *.o 
	@printf "\033[1;36mObject Files Deleted !\033[0m\n"

fclean : clean
	@rm  -rf $(NAME) 		
	@printf "\033[1;36mProgram Deleted !\033[0m\n"

re : fclean all