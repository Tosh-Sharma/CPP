NAME = megaphone

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = $(NAME).cpp

OBJS = $(SRCS:.cpp=.o)

$(NAME):	$(SRCS)
			$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all:	$(NAME)

clean:	rm -f $(OBJS)

fclean:	clean
		rm $(NAME)