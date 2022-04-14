BLACK='\u001b[30m'
RED='\u001b[31m'
GREEN="\u001b[32m"
YELLOW='\u001b[33m'
BLUE='\u001b[34m'
MAGENTA='\u001b[35m'
CYAN='\u001b[36m'
WHITE='\u001b[37m'
RESET='\u001b[0m'

NAME = testing_norm_lib
NAME_TEST = testing_test_lib
SRCS = main.cpp 
INC_NAME = dequeu.hpp vector.hpp  
INC_PATH = containers/srcs/containers
INC = $(adprefix $(INC_PATH), $(INC_NAME))
OBJ = $(SRCS:.cpp=.o)
OBJ_FOLDER = objects/
OBJS = $(addprefix $(OBJ_FOLDER), $(OBJ))
CC = c++ -Wall -Wextra -Werror -fsanitize=address -std=c++98

# Objects
all: $(NAME)

$(OBJ_FOLDER)%.o: %.cpp
	@echo -n Building Objects 
	@mkdir -p	$(OBJ_FOLDER)
	@$(CC) -c $< -o $@
	@echo " ✅"

$(NAME): $(OBJS)
	@echo -n Creating test with normal lib 
	@$(CC) $(OBJS) -o $(NAME)
	@echo " ✅"
	@echo -n Creating test with test lib 
	@$(CC) $(OBJS) -D REAL_LIB=0 -o $(NAME_TEST)
	@echo " ✅"
	@echo -n Creating test with test lib 
	@mkdir -p testResultFolder
	@./$(NAME) 10 > testResultFolder/tmp_test_norm_lib
	@./$(NAME_TEST) 10 > testResultFolder/tmp_test_test_lib
	@echo " ✅"
	@echo "Showing result difference with diff : "
	@diff tmp_test_norm_lib tmp_test_test_lib

clean:
	@echo -n Cleaning objects files
	@rm -f $(OBJS)
	@echo " ✅"

fclean: clean
	@echo -n Cleaning all outputs
	@rm -f $(NAME)
	@rm -f $(NAME_TEST)
	@rm -f testResultFolder/tmp_test_norm_lib 
	@rm -f testResultFolder/tmp_test_test_lib
	@echo " ✅"

re: fclean $(NAME)
