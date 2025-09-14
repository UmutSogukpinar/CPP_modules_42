NAME = mutantStack

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRCS =	main.cpp

INCLUDES = MutantStack.hpp

all : $(NAME)

$(NAME): $(INCLUDES)
	@$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)
	@echo "Program compiled -> $(NAME)"

clean :
	@echo "(clean) Nothing to do."

fclean :
	@$(RM) $(NAME)
	@echo "Removing $(NAME)!"


re : fclean all

.PHONY: all clean fclean re
