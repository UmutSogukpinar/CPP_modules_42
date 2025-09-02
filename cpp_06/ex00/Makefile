NAME    = converter

CXX     = c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRCS    = main.cpp ScalarConverter.cpp ato.cpp

all: $(NAME)

$(NAME):
	@$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)
	@echo "Build complete: \"$(NAME)\""

clean:
	@echo "Nothing to clean"

fclean:
	@$(RM) $(NAME)
	@echo "Executable \"$(NAME)\" removed."

re: fclean all
