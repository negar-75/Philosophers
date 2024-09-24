NAME = philo
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

HELPER = $(addprefix ./helper/, \
	ft_atoi.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putstr_fd.c \
	ft_strlen.c)

UTILS = $(addprefix ./utils/, \
	check_args.c \
	err.c \
	funcs.c \
	initial.c \
	monitor.c \
	routine.c \
	thread.c)

MAIN = ./main.c

SRCS = $(UTILS) $(HELPER) $(MAIN)
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
