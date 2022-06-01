CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c maze.c stack.c
OBJS = $(SRCS:.c=.o)

TARGET = maze.out

all : fclean $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
	rm -f $(OBJS)

fclean :
	rm -f $(OBJS) $(TARGET)

%.o : %.c
	$(CC) $(CFLAGS) -c $^
