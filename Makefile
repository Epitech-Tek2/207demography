##
## EPITECH PROJECT, 2021
## demography
## File description:
## Makefile
##

CXX	= g++

RM	= rm -f

SRC	=	sources/main.cpp \
		sources/demograph.cpp

NAME	=	207demography

CXXFLAGS	=	-I./include -Wall -Wextra -std=c++14

OBJS	=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $(NAME) $(CXXFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re