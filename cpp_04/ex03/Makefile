NAME = a.out

CHR_DIR = character
MTR_DIR = materia
CURE_DIR = $(MTR_DIR)/cure
ICE_DIR = $(MTR_DIR)/ice

INCLUDES = -I$(CHR_DIR) -I$(MTR_DIR) -I$(CURE_DIR) -I$(ICE_DIR)

CXX = c++ 
CXXFLAGS = -Wall -Wextra -Werror $(INCLUDES) -std=c++98

SRCS =	main.cpp						\
		$(CHR_DIR)/Character.cpp		\
		$(MTR_DIR)/AMateria.cpp			\
		$(MTR_DIR)/MateriaSource.cpp	\
		$(CURE_DIR)/Cure.cpp			\
		$(ICE_DIR)/Ice.cpp

all: $(NAME)

$(NAME): $(SRCS)
	@$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)
	@echo "Compilation complete: $(NAME)"

clean:
	@echo "Object files removed."

fclean: clean
	@$(RM) $(NAME)
	@echo "Executable removed."

re: fclean all

.PHONY: all clean fclean re
