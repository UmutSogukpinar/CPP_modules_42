NAME = bureaucrat
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

FORM_DIR = form
RR_DIR = $(FORM_DIR)/robotomy_request
SC_DIR = $(FORM_DIR)/shrubbery_creation
PP_DIR = $(FORM_DIR)/presidential_pardon

INCLUDES = -I$(FORM_DIR) -I$(SC_DIR) -I$(RR_DIR) -I$(SC_DIR) -I$(PP_DIR) -I.

RM = rm -rf

SRCS = 	main.cpp								\
		Bureaucrat.cpp							\
		$(FORM_DIR)/AForm.cpp					\
		$(SC_DIR)/ShrubberyCreationForm.cpp		\
		$(RR_DIR)/RobotomyRequestForm.cpp		\
		$(PP_DIR)/PresidentialPardonForm.cpp

OBJS = $(SRCS:.cpp=.o)

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