CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -f
NAME	= btc
SRCS	= main.cpp BitcoinExchange.cpp

OBJS=${SRCS:.cpp=.o}

all:    ${NAME}

${NAME}:        ${OBJS}
		${CC} ${CFLAGS} -o ${NAME} ${OBJS}

%.o: %.cpp
		${CC} ${CFLAGS} -c $< -o $@

clean:
		@${RM} ${OBJS}

fclean:         clean
		@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re