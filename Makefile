NAME =		webserv

SRCS =		srcs/main.cpp 

INCLUDES =	includes/webserv.hpp

CC =		clang++

FLAGS =		-Wall -Wextra -Werror --std=c++98

.PHONY: 	all clean fclean re

all: 		$(NAME)

$(NAME):	$(INCLUDES) $(SRCS)
			$(CC) $(SRCS) $(FLAGS) -o $@

clean:
			rm -rf *.o

fclean:		clean
			rm -rf $(NAME)
