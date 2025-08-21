CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME     = easyfind
SRC      = main.cpp

all:
	@echo "Compiling $(SRC) -> $(NAME)"
	@$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)
	@echo "Build complete"

clean:
	@echo "(clean) Nothing to do."

fclean:
	@echo "Removing $(NAME)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
