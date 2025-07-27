NAME = Animals

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

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
	$(RM) $(NAME)
	@echo "Executable removed."

re: fclean all

.PHONY: all clean fclean re
