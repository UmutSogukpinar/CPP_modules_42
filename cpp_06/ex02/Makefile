NAME        = identify
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98
INC_FLAG    = -Iincludes

SRCS        = main.cpp identify.cpp

all: $(NAME)

$(NAME):
	@$(CXX) $(CXXFLAGS) $(INC_FLAG) $(SRCS) -o $(NAME)
	@echo "Build complete: \"$(NAME)\""


clean:
	@echo "Nothing to clean"

fclean:
	@rm -f $(NAME)
	@echo "Executable \"$(NAME)\" removed."

re: fclean all

.PHONY: all clean fclean re
