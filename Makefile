NAME = testing_norm_lib
NAME_TEST = testing_test_lib
SRCS = main2.cpp 
INC_NAME = vector.hpp  
INC_PATH = containers/srcs/containers
INC = $(adprefix $(INC_PATH), $(INC_NAME))
OBJ = $(SRCS:.cpp=.o)
OBJ_FOLDER = objects/
OBJS = $(addprefix $(OBJ_FOLDER), $(OBJ))
CC = c++ -Wall -Wextra -Werror -fsanitize=address -std=c++98

# Objects
all: $(NAME)

$(OBJ_FOLDER)%.o: %.cpp
	@echo -n Building objects
	@mkdir -p	$(OBJ_FOLDER)
	@$(CC) -c $< -I srcs/containers -o $@
	@echo " ✅"

$(NAME): $(OBJS)
	@echo -n Creating test with normal lib
	@$(CC) $(OBJS) -o $(NAME)
	@echo " ✅"
	@echo -n Creating test with test lib
	@$(CC) -D real $(OBJS) -o $(NAME_TEST)
	@echo " ✅"
	@echo -n Creating test with normal container
	@mkdir -p testResultFolder
	@./$(NAME) > testResultFolder/tmp_test_norm_lib
	@echo -n Creating test with test container
	@./$(NAME_TEST) > testResultFolder/tmp_test_test_lib
	@echo " ✅"
	@echo "Showing result difference with diff : "
	@diff testResultFolder/tmp_test_norm_lib testResultFolder/tmp_test_test_lib
	@cat testResultFolder/tmp_test_test_lib

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
	@rm -f testing_norm_lib
	@rm -f testing_test_lib 
	@echo " ✅"

re: fclean $(NAME)
