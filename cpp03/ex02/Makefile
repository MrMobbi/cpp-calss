
NAME		= ex02

SRCS		= main.cpp\
			  ClapTrap.cpp\
			  ScavTrap.cpp\
			  FragTrap.cpp

OBJS		= $(SRCS:.cpp=.o)

CC			= c++ -g #-fsanitize=address

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
