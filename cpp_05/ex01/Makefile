NAME = bureaucrat
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

SRCS = main.cpp Bureaucrat.cpp Form.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(SRCS)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo $(NAME) created successfully.

clean:
	@echo Object files removed.

fclean: clean
	@$(RM) $(NAME)
	@echo Executable removed.

re: fclean all

.PHONY: all clean fclean re