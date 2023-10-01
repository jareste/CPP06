# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/29 14:38:53 by jareste-          #+#    #+#              #
#    Updated: 2023/10/01 19:51:18 by jareste-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ScalarConverter

#########
RM = rm -f
CC = c++
CFLAGS = -Werror -Wextra -Wall -std=c++98 -g -fsanitize=address
#########

#########
FILES = main ScalarConverter

SRC = $(addsuffix .cpp, $(FILES))

vpath %.cpp 
#########

#########
OBJ = $(SRC:.cpp=.o)
DEP = $(addsuffix .d, $(basename $(OBJ)))
#########

#########
%.o: %.cpp 
	@${CC} $(CFLAGS) -MMD -c $< -o $@

all:
	@$(MAKE) $(NAME) --no-print-directory

$(NAME):: $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "EVERYTHING DONE✌️   "

clean:
	@$(RM) $(OBJ) $(DEP) --no-print-directory
	@echo "OBJECTS REMOVED😭   "

fclean: clean
	@$(RM) $(NAME) --no-print-directory
	@echo "EVERYTHING REMOVED😭   "

re:	fclean all

.PHONY: all clean fclean re

-include $(DEP)
#########

