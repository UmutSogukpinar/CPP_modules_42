NAME        = identify
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98
INC_FLAG    = -Iincludes

SRCS        = main.cpp identify.cpp

all: $(NAME)

$(NAME):
	@echo "Building $(NAME)..."
	$(CXX) $(CXXFLAGS) $(INC_FLAG) $(SRCS) -o $(NAME)
	@echo "Build complete: $(NAME)"

clean:
	@echo "Nothing to clean (no object files)"

fclean:
	@echo "Removing binary: $(NAME)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
