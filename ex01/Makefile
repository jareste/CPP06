# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/29 14:38:53 by jareste-          #+#    #+#              #
#    Updated: 2023/10/02 15:50:04 by jareste-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Serializer

#########
RM = rm -f
CC = c++
CFLAGS = -Werror -Wextra -Wall -std=c++98 -g -fsanitize=address
#########

#########
FILES = main Serializer

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

