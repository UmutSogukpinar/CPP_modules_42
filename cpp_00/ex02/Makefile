NAME = Account
CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	Account.cpp \


OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)
	@echo "Compilation complete. Executable: $(NAME)"

%.o: %.cpp
	@$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo "Object files removed."

fclean: clean
	@rm -f $(NAME)
	@echo "Executable removed."

re: fclean all

.PHONY: all clean fclean