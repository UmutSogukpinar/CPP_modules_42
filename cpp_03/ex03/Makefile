NAME = DiamondTrap

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

SRCS =	main.cpp		\
		ClapTrap.cpp	\
		FragTrap.cpp	\
		ScavTrap.cpp	\
		DiamondTrap.cpp

all: $(NAME)

$(NAME): $(SRCS)
	@$(CXX) $(CXXFLAGS) ${SRCS} -o $(NAME)
	@echo "Compilation complete: $(NAME)"

clean:
	@echo "Object files removed."

fclean: clean
	@$(RM) $(NAME)
	@echo "Executable removed."

re: fclean all

.PHONY: all clean fclean re
