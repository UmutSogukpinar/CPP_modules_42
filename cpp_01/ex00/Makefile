CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	main.cpp		\
		Zombie.cpp		\
		newZombie.cpp	\
		randomChump.cpp

OBJS = $(SRC:.cpp=.o)

all: $(OBJS)

test: all
	@echo "Running tests..."
	@$(CC) $(CPPFLAGS) -o $(TEST) $(TEST).cpp $(OBJS)
	@./$(TEST)
	@echo "Tests completed."

$(NAME): $(OBJS)
	@echo "Compilation complete."

%.o: %.cpp
	@$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo "Object files removed."

fclean: clean
	@rm -f $(TEST)
	@echo "Executable removed."

re: fclean all

.PHONY: all clean fclean re