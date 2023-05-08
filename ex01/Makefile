# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchennak <jchennak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 19:12:43 by jawaher           #+#    #+#              #
#    Updated: 2023/05/09 00:03:34 by jchennak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = c++
NAME = RPN
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS =  main.cpp \
		RPN.cpp  \

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