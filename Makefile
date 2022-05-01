NAME = testing_norm_lib
NAME_TEST = testing_test_lib
SRCS = main2.cpp 
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
	@echo -n Building objects
	@mkdir -p	$(OBJ_FOLDER)
	@$(CC) -c $< -o $@
	@echo " ✅"

$(NAME): $(OBJS)
	@echo -n Creating test with normal lib
	@$(CC) -D REAL_LIB=1 $(OBJS) -o $(NAME)
	@echo " ✅"
	@echo -n Creating test with test lib
	@$(CC) -D REAL_LIB=0 $(OBJS) -o $(NAME_TEST)
	@echo " ✅"
	@echo -n Creating test with normal and test lib
	@mkdir -p testResultFolder
	@./$(NAME) 10 > testResultFolder/tmp_test_norm_lib
	@./$(NAME_TEST) 10 > testResultFolder/tmp_test_test_lib
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
