CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	Account.cpp \

TEST = tests

OBJS = $(SRC:.cpp=.o)

all: $(TEST)

test: all
	@echo "Running tests..."
	@$(CXX) $(CXXFLAGS) -o $(TEST) $(TEST).cpp $(OBJS)
	@./$(TEST)
	@echo "Tests completed."

$(TEST): $(OBJS)
	@echo "Compilation complete."

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo "Object files removed."

fclean: clean
	@rm -f $(TEST)
	@echo "Executable removed."

re: fclean all

.PHONY: all clean fclean re test