CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -f
NAME	= output
SRCS	= Bureaucrat.cpp main.cpp AForm.cpp \
		 	PresidentialPardonForm.cpp \
			RobotomyRequestForm.cpp \
			ShrubberyCreationForm.cpp \
			Intern.cpp

OBJS=${SRCS:.cpp=.o}

all:    ${NAME}

${NAME}: ${OBJS}
		${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
		@${RM} ${OBJS}

fclean: clean
		@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re