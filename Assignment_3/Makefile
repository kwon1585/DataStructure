CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c tree.c queue.c
OBJS = $(SRCS:.c=.o)

TARGET = bst.out

all : fclean $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
	rm -f $(OBJS)

fclean :
	rm -f $(OBJS) $(TARGET)

%.o : %.c
	$(CC) $(CFLAGS) -c $^
