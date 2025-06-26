NAME = bureaucrat
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

SRCS = main.cpp Bureaucrat.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

.cpp.o:
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo $(NAME) created successfully.

clean:
	@$(RM) $(OBJS)
	@echo Object files removed.

fclean: clean
	@$(RM) $(NAME)
	@echo Executable removed.

re: fclean all

.PHONY: all clean fclean re