

NAME		= bureaucrat

SRCS		= main.cpp \
			  Bureaucrat.cpp \
			  AForm.cpp \
			  PresidentialPardonForm.cpp \
			  RobotomyRequestForm.cpp \
			  ShrubberyCreationForm.cpp \
			  Intern.cpp

OBJS		= $(SRCS:.cpp=.o)

ifeq ($(shell uname), Linux)
 CC			= g++
else
 CC			= c++
endif

CPPFLAGS	= -Wall -Werror -Wextra -std=c++98

EXE_NAME	= -o $(NAME)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CPPFLAGS) $(OBJS) $(EXE_NAME)

clean:
			rm -rf $(OBJS)
	
fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.cpp.o:
			$(CC) $(CPPFLAGS) -c $< -o $(<:.cpp=.o)

.PHONY:		all clean fclean re
