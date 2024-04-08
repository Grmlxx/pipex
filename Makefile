NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
SRC = 	pipex.c \
		fork_pid.c \
		pid_checks.c \
		helpers.c \
		outils.c \
		utils.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS) $(BOBJS)

fclean: clean
		$(RM) $(NAME) $(NAME_BONUS)

re: fclean all