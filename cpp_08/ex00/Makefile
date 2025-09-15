CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME     = easyfind
SRCS      = main.cpp

all: $(NAME)

$(NAME): $(SRCS)
	@echo "Compiling $(SRCS) -> $(NAME)"
	@$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)
	@echo "Build complete"

clean:
	@echo "(clean) Nothing to do."

fclean:
	@echo "Removing $(NAME)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
