NAME = megaphone
CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CPPFLAGS) -o $(NAME) $(OBJ)
	@echo "Compilation complete. Executable: $(NAME)"

%.o: %.cpp
	@$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@echo "Object files removed."

fclean: clean
	@$(RM) $(NAME)
	@echo "Executable removed."

re: fclean all

.PHONY: all clean fclean re
