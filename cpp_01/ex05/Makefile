NAME = harl

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

SRCS =	main.cpp \
		Harl.cpp \


OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	@$(CC) $(CPPFLAGS) -o $(NAME) $(OBJS)
	@echo "Compilation complete. Executable: $(NAME)"

%.o: %.cpp
	@$(CC) $(CPPFLAGS) -c $< -o $@

all: $(NAME)

clean:
	@$(RM) $(OBJS)
	@echo "Object files removed."

fclean: clean
	@$(RM) $(NAME)
	@echo "Executable removed."

re: fclean all

.PHONY: all clean fclean re