NAME = serializer

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRC = main.cpp Serializer.cpp

all: $(NAME)

$(NAME):
	@$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)
	@echo "Build complete: \"$(NAME)\""

clean:
	@echo "Nothing to clean"

fclean:
	@$(RM) $(NAME)
	@echo "Executable \"$(NAME)\" removed."

re: fclean all

.PHONY: all clean fclean re
