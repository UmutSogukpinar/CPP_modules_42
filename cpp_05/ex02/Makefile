NAME = bureaucrat

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

FORM_DIR = form
INCLUDES_DIR = includes

INCLUDES = -I$(INCLUDES_DIR)

RM = rm -rf

SRCS = 	main.cpp								\
		Bureaucrat.cpp							\
		$(FORM_DIR)/AForm.cpp					\
		$(FORM_DIR)/ShrubberyCreationForm.cpp	\
		$(FORM_DIR)/RobotomyRequestForm.cpp		\
		$(FORM_DIR)/PresidentialPardonForm.cpp


all: $(NAME)

$(NAME): $(SRCS)
	@$(CXX) $(CXXFLAGS) $(INCLUDES) $(SRCS) -o $(NAME) 
	@echo $(NAME) created successfully.

clean:
	@echo Object files removed.

fclean: clean
	@$(RM) $(NAME)
	@echo Executable removed.

re: fclean all

.PHONY: all clean fclean re