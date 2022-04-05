NAME = testing
SRCS = main.cpp 
INC_NAME = dequeu.hpp
INC_PATH = containers/
INC = $(adprefix $(INC_PATH), $(INC_NAME))
OBJ = ${SRC:.cpp=.o}
CC = c++ -Wall -Wextra -Werror -fsanitize=address -std=c++98

all: ${NAME}

# Objects
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

all: $(NAME)

$(OBJS): %.o: %.cpp
	$(CC) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
