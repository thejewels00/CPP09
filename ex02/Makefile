# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchennak <jchennak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/09 15:08:56 by jchennak          #+#    #+#              #
#    Updated: 2023/05/13 01:35:11 by jchennak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = c++
NAME = PmergeMe
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS =  main.cpp \
		PmergeMe.cpp \

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