NAME    = converter

CXX     = c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98

SRCS    = main.cpp ScalarConverter.cpp ato.cpp

all: $(NAME)

$(NAME):
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

clean:
	@echo "Nothing to clean (no object files)."

fclean:
	@rm -f $(NAME)
	@echo "Executable removed."

re: fclean all
