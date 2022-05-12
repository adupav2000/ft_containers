NAME = std_containers
FT_NAME = ft_containers
SRCS = main2.cpp 
INC_NAME = vector.hpp stack.hpp map.hpp
INC_PATH = ./inc/
INC = $(adprefix $(INC_PATH), $(INC_NAME))
OBJ = $(SRCS:.cpp=.o)
OBJ_FOLDER = obj/
OBJS = $(addprefix $(OBJ_FOLDER), $(OBJ))
CC = c++ -Wall -Wextra -Werror -fsanitize=address -std=c++98

all:	$(FT_NAME)	$(NAME) 

$(NAME):
	@${CC} ${SRCS} -I $(INC_PATH) -o $(NAME)
	@echo Finished $(FT_NAME) compilation ✅

$(FT_NAME):
	@${CC} ${SRCS} -DFT -I $(INC_PATH) -o $(FT_NAME)
	@echo Finished $(NAME) compilation ✅

main:
	@./$(FT_NAME) > $(FT_NAME)1
	@./$(NAME) > $(NAME)1
	@diff $(NAME)1 $(FT_NAME)1
	@rm $(NAME)1
	@rm $(FT_NAME)1

test:
	@echo executing tests
	@cd tests && ./do.sh

clean:
	@echo -n Cleaning objects files
	@rm -f $(OBJS)
	@echo " ✅"

fclean: clean
	@echo -n Cleaning all outputs
	@rm -f $(NAME)
	@rm -f $(FT_NAME)
	@echo " ✅"

re: fclean all

.PHONY: all fclean clean re