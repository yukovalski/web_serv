#NAME =		webserv
#
#SRCS =		srcs/main.cpp
#
#INCLUDES =	includes/webserv.hpp
#
#CC =		clang++
#
#FLAGS =		-Wall -Wextra -Werror --std=c++98
#
#.PHONY: 	all clean fclean re
#
#all: 		$(NAME)
#
#$(NAME):	$(INCLUDES) $(SRCS)
#			$(CC) $(SRCS) $(FLAGS) -o $@
#
#clean:
#			rm -rf *.o
#
#fclean:		clean
#			rm -rf $(NAME)

NAME	= webserv

FILES	= main Parser Server Socket Request
HEADERS = Webserv Parser Server Location ServConfig Socket Request

CXX		= clang++

SRC_DIR	= srcs/
OBJ_DIR	= objs/
INCLUDE_DIR = includes/

FLAGS	= -Wall -Wextra -Werror   -I $(INCLUDE_DIR) -g

SRCS 	= $(patsubst %, $(SRC_DIR)%.cpp, $(FILES))
HDRS	= $(patsubst %, $(INCLUDE_DIR)%.hpp, $(HEADERS))
OBJS 	= $(patsubst %, $(OBJ_DIR)%.o, $(FILES))

all: $(NAME)

$(NAME): $(OBJS) $(HDRS)
	$(CXX) -o $(NAME) $(OBJS) $(FLAGS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(HDRS)
	mkdir -p $(OBJ_DIR)
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f ./$(NAME)

re: fclean all

.PHONY: all clean fclean re