NAME = Animals

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp		\
		Animal.cpp		\
		Dog.cpp			\
		Cat.cpp			\
		WrongAnimal.cpp \
		WrongCat.cpp

all: $(NAME)

$(NAME): $(SRCS)
	@$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)
	@echo "Compilation complete: $(NAME)"

clean:
	@echo "Object files removed."

fclean: clean
	@echo "Executable removed."

re: fclean all

.PHONY: all clean fclean re
